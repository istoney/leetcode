/*
 ===================================================================================
 *   Description: https://leetcode.com/problems/perfect-squares/
 *      Category: DP
 *
 *       Version: 1.0
 *   Submit Time: 2016/06/25
 *      Run Time: 268ms, beats 66.88%
 *     Solutions: DP
 ===================================================================================
 */

 class Solution {
 public:
     int numSquares(int n) {
         int dp[n+1];
         dp[0] = 0;

         for(int i=1;i<=n;++i) {
             dp[i] = i;

             for(int j=1;j*j<=i;++j) {
                 dp[i] = min(dp[i], dp[i-j*j]+1);
             }
         }

         return dp[n];
     }
 };
