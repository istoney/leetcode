/*
 ===================================================================================
 *     File Name: 216 - Combination Sum III.cpp
 *   Description: https://leetcode.com/problems/combination-sum-iii/
 *        Author: Stoney
 *      Category: 数组、组合
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/29
 *      Run Time: 0ms, beats 17.78%
 *     Solutions: 非递归迭代：①如果com中已有k个数，判断sum是否为n；②否则向com中加入一个新数
 ===================================================================================
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> com({1});
        int sum = 1;

        while(true){
            if(com.back() > 9){
                sum-=com.back(); com.pop_back();
                if(com.empty()) break;
                com.back() += 1; sum += 1;
            }
            else if(com.size()==k){
                if(sum>=n){
                    if(sum==n) ans.push_back(com);
                    sum-=com.back(); com.pop_back();
                    if(com.empty()) break;
                    com.back() += 1; sum += 1;
                }
                else{
                    com.back() += 1; sum+=1;
                }

            }
            else {
                if(sum>=n){
                    sum-=com.back(); com.pop_back();
                    if(com.empty()) break;
                    com.back() += 1; sum += 1;
                }
                else {
                    com.push_back(com.back()+1); sum += com.back();
                }
            }
        }

        return ans;
    }
};
