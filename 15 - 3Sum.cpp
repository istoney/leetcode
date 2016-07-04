/*
 ===================================================================================
 *     File Name: 15 - 3Sum.cpp
 *   Description: https://leetcode.com/problems/3sum/
 *        Author: Stoney
 *      Category: 整数求和
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/03
 *      Run Time: 58ms, beats 50%
 *     Solutions: 1.对数组排序，根据0的位置对数组分段，然后又以下两种情况：小于0一个数，大于
 *                等于0有两个数；大于等于有一个数，小于0有两个数。
 *                2.遍历一个数的分段，对另一分段按照twoSum求解
 *                3.遍历遇到与上一数字相同，则跳过
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/04
 *      Run Time: 52ms, beats 83.38%
 *     Solutions: 1.先对数组排序，遍历数组选取第一个数，然后在第一个后面的范围进行twoSum计算
 *                选取后面两个数;
 *                2.第一个数遍历时，条件为小于等于0，且遇到相同的数只计算一次；
 ===================================================================================
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;

        sort(nums.begin(), nums.end());
        int piv = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        if(piv+2<nums.size() && nums[piv+2]==0){
            vector<int> v(3, 0);
            ans.push_back(v);
        }
        if(piv==0) return ans;

        for(int i=0;i<piv;++i){
            if(i>0 && nums[i-1]==nums[i]) continue;

            int target = -nums[i];
            int front=piv, back=nums.size()-1;
            while(front < back){
                int sum = nums[front]+nums[back];
                if(sum<target) ++front;
                else if(sum>target) --back;
                else{
                    vector<int> v(3, 0);
                    v[0] = nums[i];
                    v[1] = nums[front];
                    v[2] = nums[back];
                    ans.push_back(v);
                    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
                    while(++front<=back && nums[front-1]==nums[front]) {}
                    while(--back>=front && nums[back+1]==nums[back]) {}
                }
            }
        }

        for(int i=piv;i<nums.size();++i){
            if(i>piv && nums[i-1]==nums[i]) continue;

            int target = -nums[i];
            int front=0, back=piv-1;
            while(front < back){
                int sum = nums[front]+nums[back];
                if(sum<target) ++front;
                else if(sum>target) --back;
                else{
                    vector<int> v(3, 0);
                    v[2] = nums[i];
                    v[0] = nums[front];
                    v[1] = nums[back];
                    ans.push_back(v);
                    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
                    while(++front<=back && nums[front-1]==nums[front]) {}
                    while(--back>=front && nums[back+1]==nums[back]) {}
                }
            }
        }

        return ans;
    }
};

// class Solution{
// public:
//     vector<vector<int> > threeSum(vector<int> nums){
//     	vector<vector<int> > ans;
//     	if(nums.size()<3) return ans;
//
//         sort(nums.begin(), nums.end());
//
//         for(int i=0;i<nums.size()-2 && nums[i]<=0;++i){
//             if(i>0 && nums[i-1]==nums[i]) continue;
//
//             int target = -nums[i];
//             int front=i+1, back=nums.size()-1;
//             while(front < back){
//                 int sum = nums[front]+nums[back];
//                 if(sum<target) ++front;
//                 else if(sum>target) --back;
//                 else{
//                     vector<int> v(3, 0);
//                     v[0] = nums[i];
//                     v[1] = nums[front];
//                     v[2] = nums[back];
//                     ans.push_back(v);
//                     while(++front<=back && nums[front-1]==nums[front]) {}
//                     while(--back>=front && nums[back+1]==nums[back]) {}
//                 }
//             }
//         }
//
//         return ans;
//     }
// };
