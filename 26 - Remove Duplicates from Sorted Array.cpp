/*
 ===================================================================================
 *     File Name: 26 - Remove Duplicates from Sorted Array.cpp
 *   Description: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *        Author: Stoney
 *      Category: 数组
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/14
 *      Run Time: 32ms, beats 37.53%
 *     Solutions: 新建一个数组，index记录新数组待写入的位置，遍历nums，若第i个数不是重复，
 *                将其拷贝到新数组中。该过程中index<=i，因此可以复用nums,不需要新建数组
 ===================================================================================
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for(int i=0;i<nums.size();++i){
            if(i==0 || nums[i]!=nums[i-1])
                nums[index++] = nums[i];
        }

        return index;
    }
};
