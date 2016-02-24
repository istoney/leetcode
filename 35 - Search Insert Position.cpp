/*
 ===================================================================================
 *     File Name: 35 - Search Insert Position.cpp
 *   Description: https://leetcode.com/problems/search-insert-position/
 *        Author: Stoney
 *      Category: 数组，查找
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/22
 *      Run Time: 8ms, beats 4.06%
 *     Solutions: 二分：查找下界
 ===================================================================================
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        return low_bounce(nums.begin(), nums.end(), target)-nums.begin();
    }

    vector<int>::iterator low_bounce(vector<int>::iterator begin, vector<int>::iterator end, int target){
        if(end-begin < 2)
            if(*begin>=target) return begin;
            else return end;

        vector<int>::iterator mid = begin+(end-begin)/2;
        if(*mid>=target){
            if(*(mid-1)<target) return mid;
            else return low_bounce(begin, mid-1, target);
        }
        else return low_bounce(mid, end, target);
    }
};
