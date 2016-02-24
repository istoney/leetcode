/*
 ===================================================================================
 *     File Name: 33 - Search in Rotated Sorted Array.cpp
 *   Description: https://leetcode.com/problems/search-in-rotated-sorted-array/
 *        Author: Stoney
 *      Category: 数组，二分
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/21
 *      Run Time: 4ms, beats 11.68%
 *     Solutions: 二分：首先二分查找pivot位置，然后对pivot分割的两段进行普通二分查找
 ===================================================================================
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;

        //pivot即最小元素旋转后的位置
        vector<int>::iterator pivot = findPivot(nums.begin(), nums.end());

        vector<int>::iterator it = find(nums.begin(), pivot, target);
        if(it != pivot) return it-nums.begin();

        it = find(pivot, nums.end(), target);
        if(it!=nums.end()) return it-nums.begin();
        return -1;
    }

    //pivot的判定规则是前面的元素大于本元素
    vector<int>::iterator findPivot(vector<int>::iterator begin, vector<int>::iterator end){
        if(end-begin < 2) return begin;

        vector<int>::iterator mid = begin + (end-begin)/2;
        if(*(mid-1) > *mid) return mid;
        else if(*begin > *mid) return findPivot(begin, mid);
        else return findPivot(mid, end);
    }
};
