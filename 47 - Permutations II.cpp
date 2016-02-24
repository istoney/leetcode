/*
 ===================================================================================
 *     File Name: 47 - Permutations II.cpp
 *   Description: https://leetcode.com/problems/permutations-ii/
 *        Author: Stoney
 *      Category: 数组，排列组合
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/21
 *      Run Time: 32ms, beats 46.97%
 *     Solutions: DFS
 ===================================================================================
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 2){ans.push_back(nums); return ans;}

        //without sorting, will meet TLE
        sort(nums.begin(), nums.end());
        f(ans, nums, 0, nums.size());
        return ans;
    }

    void f(vector<vector<int>> &ans, vector<int> v, int l, int n){
        if(l == n-1){
			ans.push_back(v);
			return;
		}

        for(int i=l;i<n;++i){
            //ignore swap of duplicates
            if(v[i]==v[l] && i!=l) continue;
            swap(v[i], v[l]);
            f(ans, v, l+1, n);
        }
    }
};


int main(){
    vector<int> v({3,3,0,0,2,3,2});
    Solution s;
    s.permuteUnique(v);
    return 0;
}
