/*
 ===================================================================================
 *     File Name: 31 - Next Permutation.cpp
 *   Description: https://leetcode.com/problems/next-permutation/
 *        Author: Stoney
 *      Category: 数组，排列组合
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/19
 *      Run Time: 12ms, beats 8.62%
 *     Solutions: 倒序第一对正序数字，交换后排序
 ===================================================================================
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    /*
    * 给定数组，求出大于目前排列的下一个排列顺序
    * 1.倒序查找第一个正序的数对（下例中6、8）,则6为left位置
    * 2.在left,end之间倒序查找第一个大于left的位置（下例中的7）
    * 3.交换left,right,对[left+1，end]排序
    *           left  right
    * 1 2 3 4 9  6  8  7  5
    */
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2) return;

        int left = nums.size()-2;
        for(int i=nums.size()-2;i>=0;--i)
            if(nums[i]<nums[i+1]){left = i;break;}

        int right = nums.size();
        for(int i=nums.size()-1;i>left;--i)
            if(nums[i]>nums[left]){right=i;break;}

        if(right==nums.size()){
            sort(nums.begin(), nums.end());
            return;
        }
        else{
            swap(nums[left], nums[right]);
            sort(nums.begin()+left+1, nums.end());
            return;
        }
    }
};

int main(){
    vector<int> v({1, 1});
    Solution s;
    s.nextPermutation(v);
    return 0;
}
