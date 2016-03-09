/*
 ===================================================================================
 *     File Name: 268 - Missing Number.cpp
 *   Description: https://leetcode.com/problems/missing-number/
 *        Author: Stoney
 *      Category: 数组，查找
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/02
 *      Run Time: 36ms, beats 22.37%
 *     Solutions: 交换排序：与#41思路相同，本题中唯一的非法数字为n，因此只需对nums[i]==n
 *                时特殊处理即可
 *
 *       Version: 2.0
 *   Submit Time: 2016/03/02
 *      Run Time: 32ms, beats 77.97%
 *     Solutions: 位操作：res初始为0，然后与[0, 1, 2,..., n]做亦或运算；然后与nums中的
 *                所有数字做亦或运算，结果为消失的数字
 ===================================================================================
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;){
            if(nums[i]==i || nums[i]==n) ++i;
            else swap(nums[i], nums[nums[i]]);
        }

        for(int i=0;i<n;++i)
            if(nums[i]!=i) return i;
        return n;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int res = n;
        for(int i=0;i<n;++i){
            res = res^nums[i];
            res = res^i;
        }
        return res;
    }
};
