/*
 ===================================================================================
 *     File Name: 14 - Longest Common Prefix.cpp
 *   Description: https://leetcode.com/problems/longest-common-prefix/
 *        Author: Stoney
 *      Category: 字符串操作
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/12
 *      Run Time: 4ms, beats 37.26%
 *     Solutions: 先排序，然后对排序第一和最后的字符串查找相同前缀
 ===================================================================================
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        sort(strs.begin(), strs.end());

        string ans = "";
        int n = strs.size()-1;
        for(int i=0;i<strs[0].size();ans+=strs[0][i],++i){
            if(i>=strs[n].size() || strs[0][i]!=strs[n][i])
                return ans;
        }

        return ans;
    }
};
