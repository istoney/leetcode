/*
 ===================================================================================
 *     File Name: 153 - Maximum Product Subarray.cpp
 *   Description: https://leetcode.com/problems/maximum-product-subarray/
 *        Author: Stoney
 *      Category: 数组
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/13
 *      Run Time: 4ms, beats 73.57%
 *     Solutions: 1.0将数组分段
 *                2.每一分段内，若乘积为正，则为最大乘积；若乘积为负，则最大乘积为第一个
 *                负数之后的乘积，或从开始到最后一个负数之前的乘积
 ===================================================================================
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 0x80000000;

        int first=-1, last=-1, prd=0x80000000, firstPrd=0x80000000, lastPrd=0x80000000;
        bool start = false;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=0){
                if(!start){
                    start = true;
                    if(nums[i]<0){
                        if(first<0) first=i;
                        last=i; lastPrd=prd;
                    }
                    prd = nums[i];
                } else {
                    if(first>=0){
                        if(first==i-1) firstPrd=nums[i];
                        else firstPrd*=nums[i];
                    }

                    if(nums[i]<0){
                        if(first<0) first=i;
                        last=i; lastPrd=prd;
                    }
                    prd *= nums[i];
                }
            }
            else if(start){
                ans = max(ans, prd);
                ans = max(ans, firstPrd);
                ans = max(ans, lastPrd);
                ans = max(ans, 0);

                start = false;
                first=-1; prd=0x80000000; firstPrd=0x80000000; lastPrd=0x80000000;
            }
            else ans = max(ans, 0);
        }

        ans = max(ans, prd);
        ans = max(ans, firstPrd);
        ans = max(ans, lastPrd);

        return ans;
    }
};
