/*
 ===================================================================================
 *     File Name: 18 - 4Sum.cpp
 *   Description: https://leetcode.com/problems/4sum/
 *        Author: Stoney
 *      Category: 整数求和
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/09
 *      Run Time: 84ms, beats 61.71%
 *     Solutions: 遍历枚举：类似3Sum解法，排序后遍历数组，选取数字后再次遍历，然后对剩余
 *                的范围进行twoSum计算;twoSum计算中使用二分搜索进行优化
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/04
 *      Run Time: 28ms, beats 84.77%
 *     Solutions: 基于方法1改进，进行剪枝
 ===================================================================================
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4) return ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        for(int i=0;i<n-3;++i){
            if(i>0 && nums[i]==nums[i-1]) continue;
            //剪枝
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1] < target) continue;

            for(int j=i+1;j<n-2;++j){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                //剪枝
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1] < target) continue;

                int new_target = target-nums[i]-nums[j];
                int left=j+1, right=nums.size()-1;

                while(left<right){
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum<target){
                        vector<int>::iterator it = lower_bound(nums.begin()+left+1, nums.begin()+right, new_target-nums[right]);
                        if(nums.begin()+right==it) break;
                        else left=distance(nums.begin(), it);
                    }
                    else if(sum > target){
                        vector<int>::iterator it = lower_bound(nums.begin()+left+1, nums.begin()+right, new_target-nums[left]);
                        if(nums.begin()+right==it) --right;
                        else right=distance(nums.begin(),it);
                    }
                    else {
                        vector<int> v({nums[i],nums[j],nums[left],nums[right]});
                        ans.push_back(v);
                        while(++left<right && nums[left]==nums[left-1]){}
                        while(--right>left && nums[right]==nums[right+1]){}
                    }
                }
            }
        }

        return ans;
    }
};

int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(-1);
    v.push_back(0);
    Solution s;
    s.fourSum(v, 2);
    return 0;
}
