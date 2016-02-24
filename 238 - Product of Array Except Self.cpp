/*
 ===================================================================================
 *     File Name: 238 - Product of Array Except Self.cpp
 *   Description: https://leetcode.com/problems/product-of-array-except-self/
 *        Author: Stoney
 *      Category: 数组运算
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/12
 *      Run Time: 64ms, beats 15.10%
 *     Solutions: 首先计算乘积，然后逐个除以元素。但是注意数组中存在0的情况，若存在一个0，
 *                只有为0的位置不为0，其他部分为0；若有两个以上为0，全部为0.
 ===================================================================================
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);

        int gotZero = 0, pos;
        long pro = 1;
        for(int i=0;i<nums.size();++i) {
            if(nums[i]==0){
                ++gotZero; pos=i;
            }
            else pro*=nums[i];
        }

        if(gotZero==0){
            for(int i=0;i<ans.size();++i) ans[i] = pro/nums[i];
        }
        else if(gotZero==1) ans[pos]=pro;

        return ans;
    }
};
