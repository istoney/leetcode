/*
 ===================================================================================
 *   Description: https://leetcode.com/problems/interleavig-string/
 *      Category: DP
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/21
 *      Run Time: 0ms, beats 84.94%
 *     Solutions: 1.DP[i][j]记录s3的[0:i+j-1]是否是s1[0:i-1]和s2[0:j-1]的interleaving
 *                2.初始化，DP[0][0]=true, DP[i][0] (1<=i<=M)看s1[0:i-1]是否与s3[0:i-1]相等；
 *                  DP[0][j] (1<=j<=N)看s2[0:j-1]是否与s3[0:j-1]相等；
 *                3.计算DP[i][j]，若s1[i-1]==s3[i+j-1] 且 DP[i-1][j]为true，即为真；
 *                  或者s2[j-1]==s3[i+j-1] 且 DP[i][j-1]为true；
 ===================================================================================
 */

 class Solution {
 public:
     bool isInterleave(string s1, string s2, string s3) {
         int M = s1.length();
         int N = s2.length();

         bool dp[M+1][N+1];

         dp[0][0] = true;
         for(int i=1;i<=M;++i)
             dp[i][0] = (dp[i-1][0] && s1[i-1]==s3[i-1]);

         for(int j=1;j<=N;++j)
             dp[0][j] = (dp[0][j-1] && s2[j-1]==s3[j-1]);

         for(int i=1;i<=M;++i) {
             for(int j=1;j<=N;++j) {
                 dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
             }
         }

         return s3.length()==M+N && dp[M][N];
     }
 };
