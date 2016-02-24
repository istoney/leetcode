/*
 ===================================================================================
 *     File Name: 30 - Substring with Concatenation of All Words.cpp
 *   Description: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 *        Author: Stoney
 *      Category: 字符串、滑动窗口
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/16
 *      Run Time: 992ms, beats 12.33%
 *     Solutions: 遍历枚举
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/17
 *      Run Time: 48ms, beats 85.21%
 *     Solutions: 滑动窗口
 ===================================================================================
 */
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    /*
    * 1.遍历字符串，以每个字符为起点，判断长度为k(words length)的子串是否属于words，
    * 2.直到words中所有单词均出现，或存在一个子串不属于words，然后在从下一个字符继续
    * 3.使用词典(Map)记录word的出现
    */
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.empty() || words.empty()) return ans;

        int k = words[0].size(), wn = words.size();
        if(s.size() < wn*k) return ans;

        //构建词典，记录每个单词应该出现的次数
        unordered_map<string, int> M;
        for(int i=0;i<words.size();++i) ++M[words[i]];

        int count, start;
        string str;
        unordered_map<string, int> subM;

        //以每个字符为起点查找
        for(int i=0;i<s.size();++i){
            unordered_map<string, int> subM;
            count = 0;
            start = i;

            while(count < wn){
                str = s.substr(start, k);
                if(M.find(str) != M.end()){
                    if(subM[str] < M[str]){++count; ++subM[str]; start+=k;}
                    else break;
                }
                else break;
            }

            if(count == wn) ans.push_back(i);
        }

        return ans;
    }
};

class Solution {
public:
    /*
    * 1.word长度为k，则一个单词开始的位置有k中可能，第0,1..k-1个字符
    * 2.对上述k种可能，以开始字符为左边缘构建滑动窗口，按单词长度k选取字符串，在词典中查找
    * 3.若词典中没有该词，将窗口开始移动到下一个单词的开始(next+k)，清空，重新开始
    * 4.若词典中出现了该词，检查本窗口中该单词的出现次数，若小于词典中次数，加1继续
    * 5.若大于等于，从左侧缩减窗口，直到该单词的次数小于词典，然后加1，继续
    */
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.empty() || words.empty()) return ans;

        int k = words[0].size(), wn = words.size();
        if(s.size() < wn*k) return ans;

        unordered_map<string, int> M;
        for(int i=0;i<words.size();++i){
            ++M[words[i]];
        }

        int count, start, next;
        unordered_map<string, int> subM;
        string str;

        for(int i=0;i<k;++i){
            unordered_map<string, int> subM;
            count = 0;
            start = i;  //窗口开始位置
            next = i;   //下一个单词开始位置

            while(next <= s.size()-k){
                str = s.substr(next, k);
                if(M.count(str)){
                    if(subM[str] < M[str]){
                        ++count;
                        ++subM[str];
                        next+=k;

                        if(count == wn){
                            //单词数与词典一致，找到目标子串
                            ans.push_back(start);
                            str = s.substr(start, k);
                            --count;
                            --subM[str];
                            start += k;
                        }
                    }
                    else {
                        //窗口中str出现次数超出词典，缩减窗口
                        while(subM[str] >= M[str]){
                            str = s.substr(start, k);
                            --subM[str];
                            --count;
                            start += k;
                        }
                    }
                }
                else {
                    count = 0;
                    subM.clear();
                    next += k;
                    start = next;
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<string> v({"ab","ba","ba"});
    s.findSubstring("ababaab", v);
    return 0;
}
