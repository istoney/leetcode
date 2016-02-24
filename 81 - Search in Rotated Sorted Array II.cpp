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
 *      Run Time: 8ms, beats 12.50%
 *     Solutions: 二分：首先二分查找pivot位置，然后对pivot分割的两段进行普通二分查找
 ===================================================================================
 */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;

        vector<int>::iterator pivot = findPivot(nums.begin(), nums.end());
        vector<int>::iterator it = find(nums.begin(), pivot, target);
        if(it!=pivot) return true;

        it = find(pivot, nums.end(), target);
        if(it!=nums.end()) return true;

        return false;
    }

    vector<int>::iterator findPivot(vector<int>::iterator begin, vector<int>::iterator end){
        if(end-begin < 2) return begin;

        vector<int>::iterator mid = begin + (end-begin)/2;
        if(*(mid-1) > *mid) return mid;
        else if(*begin > *mid) return findPivot(begin, mid);
        else return findPivot(mid, end);
    }
};
