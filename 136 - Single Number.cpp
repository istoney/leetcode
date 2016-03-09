/*
 ===================================================================================
 *     File Name: 136 - Single Number.cpp
 *   Description: https://leetcode.com/problems/single-number/
 *        Author: Stoney
 *      Category: 数组，查找
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/02
 *      Run Time: 16ms, beats 69.42%
 *     Solutions: 位操作：对所有数字亦或运算
 ===================================================================================
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();++i) res = res^nums[i];
        return res;
    }
};
