/*
 ===================================================================================
 *     File Name: 3 - Longest Substring Without Repeating Character.cpp
 *   Description: https://leetcode.com/problems/add-two-numbers/
 *        Author: Stoney
 *      Category: 无重复子串
 *       Version: 1.0
 *   Submit Time: 2016/01/11
 *      Run Time: 16ms, beats 63.99%
 *     Solutions: 1.以0为start，表示一次查找的开始。遍历字符串，查看该字符上次出现的位置，
 *                若出现在start之后，说明本次查找存在重复字符，last[s[i]]-(i-1)是一个无
 *                重复子串。更新start为last[s[i]]+1，重新开始搜索。若出现在start之前，更
 *                新位置，继续搜索。
 *                2.共255个字符，使用255一维数组存储字符位置数据。
 ===================================================================================
 */

#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];
        fill(last, last+256, -1);
        int res = 0;

        //pos to start search
        int start = 0;
        for(int i=0;i<s.size();i++){
            if(last[s[i]] >= start){
                res = max(res, i-start);
                //update search start pos
                start = last[s[i]] + 1;
            }
            //update the new pos of a
            last[s[i]] = i;
        }

        //final search from start to N
        return max(res, (int)s.size() - start);
    }
};

int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("aaa");
    return 0;
}
