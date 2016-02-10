/*
 ===================================================================================
 *     File Name: 9 - Palindrome Number.cpp
 *   Description: https://leetcode.com/problems/palindrome-number/
 *        Author: Stoney
 *      Category: 正则匹配
 *          Note: 
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/06
 *      Run Time: 4ms, beats 89.83%
 *     Solutions: 动态规划：bool类型的DP数组，大小为(m+1)*(n+1)，DP[i][j]表示s[0..i]
 *                与p[0..j]的匹配情况
 *                1.第0行、第0列分别表示s为空串、p为空串的匹配情况，DP[0][0]为true
 *                2.DP[i][j] = p[j-1]不是*，则需要p[j-1]与s[i-1]匹配，且DP[i-1][j-1]为真
 *                             p[j-1]是*，①*匹配0个字符，即p[j-2]p[j-1]不存在也匹配，即
 *                             DP[i][j-2]，②*匹配大于一个字符，即a*a，则s[i-1]与p[j-2]匹
 *                             配，且s[0..i-2]匹配a*，即DP[i-1][j]为真
 ===================================================================================
 */

#include<cstdio>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        bool dp[m+1][n+1];

        for(int i=0;i<m+1;++i){
            for(int j=0;j<n+1;++j)
                dp[i][j] = false;
        }

        dp[0][0] = true;
        for(int j=2;j<n+1;++j)
            dp[0][j] = p[j-1]=='*' && dp[0][j-2];

        for(int i=1;i<m+1;++i){
            for(int j=1;j<n+1;++j){
                if(p[j-1] == '*')
                    //a repeats 0 times in a*, so s[0..i-1] match p[0..j-3], namely dp[i][j-2]
                    //a repeats more than one times, means a*a, so, s[0..i-2] must math a*,
                    //thst's dp[i-1][j], and s[i-1] must match the character p[j-2]
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1]==p[j-2] || '.'==p[j-2]));
                else dp[i][j] = dp[i-1][j-1] && (s[i-1]==p[j-1] || '.'==p[j-1]);

                cout<<i<<" "<<j<<" "<<dp[i][j] <<endl;
            }
        }

        return dp[m][n];
    }
};

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         /**
//          * f[i][j]: if s[0..i-1] matches p[0..j-1]
//          * if p[j - 1] != '*'
//          *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
//          * if p[j - 1] == '*', denote p[j - 2] with x
//          *      f[i][j] is true iff any of the following is true
//          *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
//          *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
//          * '.' matches any single character
//          */
//         int m = s.size(), n = p.size();
//         vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
//
//         f[0][0] = true;
//         for (int i = 1; i <= m; i++)
//             f[i][0] = false;
//         // p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
//         for (int j = 1; j <= n; j++)
//             //遇到*时，f[0][j-2] -> f[0][j]
//             f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];
//
//         for (int i = 1; i <= m; i++)
//             for (int j = 1; j <= n; j++)
//                 if (p[j - 1] != '*')
//                     f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
//                 else
//                     // p[0] cannot be '*' so no need to check "j > 1" here
//                     f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
//
//         return f[m][n];
//     }
// };

int main(){
    Solution s;
    cout<<s.isMatch("aa", "a*")<<endl;
    return 0;
}
