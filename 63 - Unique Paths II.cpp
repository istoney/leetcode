/*
 ===================================================================================
 *   Description: https://leetcode.com/problems/unique-paths-ii/
 *      Category: DP
 *
 *       Version: 1.0
 *   Submit Time: 2016/06/14
 *      Run Time: 4ms, beats 15.33%
 *     Solutions: 1.DP[i][j]: num of unique paths from (0,0) to (i,j)
 *                2.DP[i][j] = 0 (if (i,j) is obstacle)
 *                             dp[i-1][j] + dp[i][j-1] (if (i,j) is empty)
 ===================================================================================
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0 || obstacleGrid[0].size()==0) return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));   //dp[i][j]: num of unique paths from (0,0) to (i,j)

        for(int i=0;i<m;++i) {
            if(!obstacleGrid[i][0]) dp[i][0] = 1;
            else break;
        }

        for(int j=0;j<n;++j) {
            if(!obstacleGrid[0][j]) dp[0][j] = 1;
            else break;
        }

        for(int i=1;i<m;++i) {
            for(int j=1;j<n;++j) {
                if(obstacleGrid[i][j]) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
