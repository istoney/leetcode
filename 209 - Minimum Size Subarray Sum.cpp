/*
 ===================================================================================
 *     File Name: 209 - Minimum Size Subarray Sum.cpp
 *   Description: https://leetcode.com/problems/minimum-size-subarray-sum/
 *        Author: Stoney
 *      Category: 数组、滑动窗口
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/17
 *      Run Time: 4ms, beats 24.62%
 *     Solutions: 滑动窗口
 ===================================================================================
 */

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;

        int len=nums.size()+1;

        int start=0, sum=0, tmp_len;
        for(int i=0;i < nums.size();++i){
            sum += nums[i];
            while(sum >= s){
                tmp_len = i-start+1;
                if(tmp_len < len) len=tmp_len;
                sum -= nums[start++];
            }
        }

        if(len > nums.size()) return 0;
        return len;
    }
};
