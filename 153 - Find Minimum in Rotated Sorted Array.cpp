/*
 ===================================================================================
 *     File Name: 81 - Search in Rotated Sorted Array II.cpp
 *   Description: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 *        Author: Stoney
 *      Category: 数组，二分
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/21
 *      Run Time: 4ms, beats 7.27%
 *     Solutions: 二分：首先二分查找pivot位置，然后对pivot分割的两段进行普通二分查找
 ===================================================================================
 */
class Solution {
public:
    //有可能旋转也有可能没旋转
    int findMin(vector<int>& nums) {
        vector<int>::iterator it = findPivot(nums.begin(), nums.end());
        if(it!=nums.end()) return *it;
        return nums[0];
    }

    vector<int>::iterator findPivot(vector<int>::iterator begin, vector<int>::iterator end){
        //范围内只有一个元素，则结果肯定不存在
        if(end-begin < 2) return end;

        vector<int>::iterator mid = begin + (end-begin)/2;
        if(*(mid-1) > *mid) return mid;
        else if(*begin > *mid){
            vector<int>::iterator it = findPivot(begin, mid);
            if(it!=mid) return it;
            return end;
        }
        else return findPivot(mid, end);
    }
};
