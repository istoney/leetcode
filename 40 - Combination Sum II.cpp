/*
 ===================================================================================
 *     File Name: 40 - Combination Sum II.cpp
 *   Description: https://leetcode.com/problems/combination-sum-ii/
 *        Author: Stoney
 *      Category: 数组、组合
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/29
 *      Run Time: 12ms, beats 56.79%
 *     Solutions: DFS:注意重复，如果cand[i]==cand[i-1]，则com+cand[i]将会与com+cand[i-1]
 *                重复
 ===================================================================================
 */

class Solution{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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

        for(int i=idx;i<cand.size() && cand[i]<=target;++i){
            //com+cand[i] will be duplicate for com+cand[i-1]
            if(i>idx && cand[i]==cand[i-1]) continue;

            com.push_back(cand[i]);
            f(ans, cand, com, i+1, target-cand[i]);
            com.pop_back();
        }
    }
};
