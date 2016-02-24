/*
 ===================================================================================
 *     File Name: 27 - Remove Element.cpp
 *   Description: https://leetcode.com/problems/remove-element/
 *        Author: Stoney
 *      Category: 数组
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/15
 *      Run Time: 8ms, beats 0.70%
 *     Solutions: 新建一个数组，index记录新数组待写入的位置，遍历nums，若第i个数不是重复，
 *                将其拷贝到新数组中。该过程中index<=i，因此可以复用nums,不需要新建数组
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/15
 *      Run Time: 4ms, beats 3.96%
 *     Solutions: 遍历数组，判断是否为val，若是则从数组尾部取值覆盖该位置，降低元素移动次数
 ===================================================================================
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;

        int i=0, index = nums.size()-1;
        while(i<index){
            if(nums[i]==val){
                nums[i] = nums[index--];
            }
            else ++i;
        }

        return nums[i]==val ? i : i+1;
    }
};
