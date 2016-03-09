/*
 ===================================================================================
 *     File Name: 41 - First Missing Positive.cpp
 *   Description: https://leetcode.com/problems/first-missing-positive/
 *        Author: Stoney
 *      Category: 数组，查找
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/02
 *      Run Time: 4ms, beats 3.55%
 *     Solutions: 查找第一个消失的正数：则长度为n的数组中应该是[1, 2, 3,..., n]
 *                1.<=0的数不应该存在，将其与结尾数字交换，并将数组长度n-1;
 *                2.>n(当前长度)的数字也不应该存在，重复的数字也不应该；
 *                3.对于<=n的数字，将其放置在对应位置上
 ===================================================================================
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int last = nums.size()-1;

        //交换排序
        for(int i=last;i>=0;){
            if(nums[i]==i+1) --i;
            else if(nums[i]<=0 || nums[i] > last+1 || nums[nums[i]-1]==nums[i]){
                if(i!=last) swap(nums[i], nums[last--]);
                else swap(nums[i--], nums[last--]);
            }
            else swap(nums[nums[i]-1], nums[i]);
        }

        //查找不对应的数字
        for(int i=0;i<=last;++i)
            if(nums[i]!=i+1)
                return i+1;
        return last+2;
    }
};
