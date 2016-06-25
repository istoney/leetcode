/*
 ===================================================================================
 *   Description: https://leetcode.com/problems/distinct-subsequence/
 *      Category: DP
 *
 *       Version: 1.0
 *   Submit Time: 2016/06/23
 *      Run Time: 8ms, beats 81.17%
 *     Solutions: 1.求s的subsquence中与t相同的个数，理解题意！！
 *                2.DP[i][j] is the number of distinct subsquence of s[0:i] and t[0:j];
 *                3.DP[i][j] =
 *                    a) s[i] equals t[j], dp[i-1][j-1] + dp[i-1][j]
 *                    b) s[i] not equals t[j], dp[i-1][j]
 ===================================================================================
 */

 class Solution {
 public:
     int numDistinct(string s, string t) {
         int M = s.length();
         int N = t.length();

         int dp[M+1][N+1];
         dp[0][0] = 1;

         for(int j=1;j<=N;++j) dp[0][j] = 0;
         //"b" and "" result is 1
         for(int i=1;i<=M;++i) dp[i][0] = 1;

         for(int i=1;i<=M;++i) {
             for(int j=1;j<=N;++j) {
                 if(s[i-1] == t[j-1])
                     dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                 else
                     dp[i][j] = dp[i-1][j];
             }
         }

         return dp[M][N];
     }
 };
