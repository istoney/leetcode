/*
 ===================================================================================
 *   Description: https://leetcode.com/problems/climbing-stairs/
 *      Category: DP
 *
 *       Version: 1.0
 *   Submit Time: 2016/06/24
 *      Run Time: 0ms, beats 12.21%
 *     Solutions: DP
 ===================================================================================
 */

 class Solution {
 public:
     int climbStairs(int n) {
         int dp[n+1];

         dp[0] = dp[1] = 1;

         for(int i=2;i<=n;++i) dp[i] = dp[i-2] + dp[i-1];

         return dp[n];
     }
 };
