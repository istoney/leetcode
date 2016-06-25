/*
 ===================================================================================
 *     File Name: 62 - Unique Paths.cpp
 *   Description: https://leetcode.com/problems/unique-paths/
 *        Author: Stoney
 *      Category: DP
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/06/10
 *      Run Time: 0ms, beats 16.18%
 *     Solutions: 1.DP从小到大计算，保存之前计算结果
 ===================================================================================
 */

  class Solution {
  public:
      int uniquePaths(int m, int n) {
          if(m == 0 || n == 0) return 0;

          int dp[m][n];

          for(int i=0;i<m;++i) dp[i][0] = 1;
          for(int j=0;j<n;++j) dp[0][j] = 1;

          for(int i=1;i<m;++i){
              for(int j=1;j<n;++j){
                  dp[i][j] = dp[i-1][j] + dp[i][j-1];
              }
          }

          return dp[m-1][n-1];
      }
  };
