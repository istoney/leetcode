/*
 ===================================================================================
 *     File Name: 76 - Minimum Window Substring.cpp
 *   Description: https://leetcode.com/problems/minimum-window-substring/
 *        Author: Stoney
 *      Category: 字符串、滑动窗口
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/17
 *      Run Time: 16ms, beats 51.14%
 *     Solutions: 滑动窗口
 ===================================================================================
 */
#include<iostream>
using namespace std;
class Solution {
public:
    /*
     * 查找s中出现所有t中字符（包括出现的次数，大于等于）的子串
     * 1.滑动窗口，选取第一个属于t的字符作为窗口左边界，记为start，向后遍历s
     * 2.若字符不属于t，继续遍历
     * 3.若字符属于t，将该字符计数加1，并判断t_count(满足t需要的字符个数)是否满足，若不
     * 满足，继续遍历；若满足，计算长度，并将窗口的左边界(start)右移
    */
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";

        int M[256] = {0}, K=t.size();
        for(int i=0;i<t.size();++i) ++M[t[i]];

        int len=s.size()+1, pos;
        int tmpM[256] = {0};
        int i=0, start=-1, t_count=0;
        while(i < s.size()){
            if(start<0){
                if(M[s[i]]){
                    t_count = 0;
                    start = i;
                }
                else ++i;
            }
            else {
                if(M[s[i]]){
                    if(++tmpM[s[i]] <= M[s[i]]) ++t_count;
                    //start右移时会出现仍然满足t的情况，如“aaabc”,"abc"
                    //直到t_count不满足t，然后将i加1，开始另一次窗口右边界右移
                    while(t_count == K){
                        int tmp_len = i-start+1;
                        if(tmp_len < len) {len=tmp_len;pos=start;}
                        if(--tmpM[s[start]] < M[s[start]]) --t_count;
                        while(++start<s.size() && !M[s[start]]) {}
                    }
                    ++i;
                }
                else ++i;
            }
        }

        if(len<=s.size()) return s.substr(pos, len);
        else return "";
    }
};
int main(){
    Solution s;
    cout<<s.minWindow("aa", "aa")<<endl;
    return 0;
}
