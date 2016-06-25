/*
 ===================================================================================
 *   Description: https://leetcode.com/problems/dungeon-game/
 *      Category: DP
 *
 *       Version: 1.0
 *   Submit Time: 2016/06/21
 *      Run Time: 10ms, beats 33.26%
 *     Solutions: 1.DP[i][j]: minimum health needed from (i,j) get to Pricess
 *                2.DP process calculate backward:
 *                      DP[i][j] = min(DP[i][j+1], DP[i+1][j]) ... 
 ===================================================================================
 */

 class Solution {
 public:
     int calculateMinimumHP(vector<vector<int>>& dungeon) {
         int M = dungeon.size();
         int N = dungeon[0].size();

         int dp[M+1][N+1];
         dp[M][N-1] = 1;
         dp[M-1][N] = 1;

         for(int j=0;j<N-1;++j) dp[M][j] = 0x7fffffff;
         for(int i=0;i<M-1;++i) dp[i][N] = 0x7fffffff;

         for(int i=M-1;i>=0;--i) {
             for(int j=N-1;j>=0;--j) {
                 int minHlth = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j];
                 dp[i][j] = minHlth <= 0 ? 1 : minHlth;
             }
         }

         return dp[0][0];
     }
 };
