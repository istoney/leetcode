/*
 ===================================================================================
 *   Description: https://leetcode.com/problems/minimum-path-sum/
 *      Category: DP
 *
 *       Version: 1.0
 *   Submit Time: 2016/06/14
 *      Run Time: 13ms, beats 22.67%
 *     Solutions: 1.DP[i][j]: minimum path sum from (0,0) to (i,j)
 *                2.The first row value is add p from the (0,0), so as the first column
 ===================================================================================
 */
 class Solution {
 public:
     int minPathSum(vector<vector<int>>& grid) {
         if(grid.size()==0 || grid[0].size()==0) return 0;
         int m = grid.size();
         int n = grid[0].size();

         int dp[m][n];

         dp[0][0] = grid[0][0];
         for(int i=1;i<m;++i) dp[i][0] = dp[i-1][0] + grid[i][0];
         for(int j=1;j<n;++j) dp[0][j] = dp[0][j-1] + grid[0][j];

         for(int i=1;i<m;++i) {
             for(int j=1;j<n;++j) {
                 dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
             }
         }

         return dp[m-1][n-1];
     }
 };
