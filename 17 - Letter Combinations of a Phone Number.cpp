/*
 ===================================================================================
 *     File Name: 17 - Letter Combinations of a Phone Number.cpp
 *   Description: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *        Author: Stoney
 *      Category: 字符串操作
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/13
 *      Run Time: 0ms, beats 7.76%
 *     Solutions: 暴力枚举：遍历所有数字对应的字符进行组合，实现上将已有的字符串放在保存，
 *                生成添加新字符时，遍历添加
 ===================================================================================
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;

        char T[8][4] = {{'a','b','c'},
                        {'d','e','f'},
                        {'g','h','i'},
                        {'j','k','l'},
                        {'m','n','o'},
                        {'p','q','r','s'},
                        {'t','u','v'},
                        {'w','x','y','z'}};
        int len[8] = {3, 3, 3, 3, 3, 4, 3, 4};

        ans.push_back("");
        for(int i=0;i<digits.size();++i){
            int n = ans.size();
            for(int j=0;j<n;++j){
                string tmp = ans[j];
                ans[j] = tmp + T[digits[i]-'2'][0];
                for(int k=1;k<len[digits[i]-'2'];++k) ans.push_back(tmp+T[digits[i]-'2'][k]);
            }
        }

        return ans;
    }
};
