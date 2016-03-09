/*
 ===================================================================================
 *     File Name: 39 - Combination Sum.cpp
 *   Description: https://leetcode.com/problems/combination-sum/
 *        Author: Stoney
 *      Category: 数组、组合
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/28
 *      Run Time: 28ms, beats 31.66%
 *     Solutions: DFS:选取第i、i+1、i+2...加入到com，进入下次迭代
 *                递归算法的快慢与递归树的规模有关系
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/29
 *      Run Time: 300ms, beats 1.67%
 *     Solutions: DP：dp[i][n]指前i个数字构成和为n的所有组合，则
 *                dp[i][n] = dp[i-1][n], dp[i-1][n-can[i]]+can[i], dp[i-1][n-2*can[i]]+2*can[i]...
 ===================================================================================
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> com;
        f(ans, candidates, com, 0, target);
        return ans;
    }

    void f(vector<vector<int>> &ans, vector<int> cand, vector<int> com, int idx, int target){
        if(!target){
            ans.push_back(com);
            return;
        }

        for(int i=idx;i<cand.size() && target>=cand[i];++i){
            com.push_back(cand[i]);
            f(ans, cand, com, i, target-cand[i]);
            com.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> dp[candidates.size()+1][target+1];
        for(int i=0;i<=candidates.size();++i) dp[i][0].push_back(vector<int>());

        for(int i=1;i<=candidates.size();++i){
            for(int n=1;n<=target;++n){

                for(int k=0;k*candidates[i-1]<=n;++k){
                    int num = n-k*candidates[i-1];
                    for(vector<int> v : dp[i-1][num]){
                        vector<int> tmp = v;
                        for(int j=1;j<=k;++j) tmp.push_back(candidates[i-1]);
                        dp[i][n].push_back(tmp);
                    }
                }
            }
        }

        return dp[candidates.size()][target];
    }
};
