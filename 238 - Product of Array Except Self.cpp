/*
 ===================================================================================
 *     File Name: 238 - Product of Array Except Self.cpp
 *   Description: https://leetcode.com/problems/product-of-array-except-self/
 *        Author: Stoney
 *      Category: 数组运算
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/27
 *      Run Time: 60ms, beats 49.65%
 *     Solutions: 动态规划：除去第i个数的乘积 = 第1到i-1元素的乘积 * i+1到n元素的；
 *                两次遍历求出1到n的各个乘积、n到1的各个乘积
 ===================================================================================
 */

 class Solution {
 public:
     vector<int> productExceptSelf(vector<int>& nums) {
         int prdFromStart[nums.size()+2];
         int prdToEnd[nums.size()+2];

         prdFromStart[0] = 1;
         for(int i=1;i<nums.size()+1;++i) prdFromStart[i] = prdFromStart[i-1]*nums[i-1];

         prdToEnd[nums.size()+1] = 1;
         for(int i=nums.size();i>0;--i) prdToEnd[i] = prdToEnd[i+1]*nums[i-1];

         vector<int> ans(nums.size(), 1);
         for(int i=0;i<nums.size();++i) ans[i] = prdFromStart[i]*prdToEnd[i+2];
         return ans;
     }
 };
