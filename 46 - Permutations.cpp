/*
 ===================================================================================
 *     File Name: 46 - Permutations.cpp
 *   Description: https://leetcode.com/problems/permutations/
 *        Author: Stoney
 *      Category: 数组，排列组合
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/19
 *      Run Time: 16ms, beats 21.24%
 *     Solutions: DFS
 ===================================================================================
 */
 #include<iostream>
 #include<vector>
 #include<stack>
 #include<algorithm>

 using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 2){ans.push_back(nums); return ans;}

        sort(nums.begin(), nums.end());
        f(ans, nums, 0, nums.size());
        return ans;
    }

    //从l位置开始的排列组合，从后面选取一个数与l交换，对l+1进行全排列
    void f(vector<vector<int>> &ans, vector<int> v, int l, int n){
        if(l == n-1) {ans.push_back(v);return;}

        for(int i=l;i<n;++i){
            swap(v[l], v[i]);
            f(ans, v, l+1, n);
            swap(v[l], v[i]);
        }
    }
};

int main(){
    Solution s;
    std::vector<int> v({0, 2});
    return 0;
}
