/*
 ===================================================================================
 *     File Name: 287 - Find the Duplicate Number.cpp
 *   Description: https://leetcode.com/problems/find-the-duplicate-number/
 *        Author: Stoney
 *      Category: 数组，重复数字
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/04
 *      Run Time: 24ms, beats 10.87%
 *     Solutions: 二分：统计1到n/2之间数字的个数，若大于n/2-1，则说明重复数字在1到n/2之间，
 *                否则出现在n/2到n之间，进入下次迭代；
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/04
 *      Run Time: 28ms, beats 4.64%
 *     Solutions: 重复数字x的个数为m，即重复m-1次，缺失数字的个数为k，则m=k+2；
 *                故，x二进制所有为1的位上计数将增加m-1,若k个缺失数字恰好在相同的位上为1，
 *                则减少次数为k，而m-1>k
 ===================================================================================
 */


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        return f(nums, 1, n+1);
    }

    //[low, up)
    int f(vector<int>nums, int low, int up){
        if(low==up-1) return low;

        int count=0;
        int mid = (low+up)/2;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>=low && nums[i]<mid) ++count;
        }

        if(count>mid-low) return f(nums, low, mid);
        else return f(nums, mid, up);
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> count(32, 0);

        int n = nums.size()-1;
        unsigned int bit = 1;

        for(int i=1;i<=n;++i){
            bit = 1;
            for(int j=1;j<=32;++j){
                if(nums[i-1] & bit) ++count[j-1];
                if(i & bit) --count[j-1];

                bit = bit << 1;
            }
        }

        bit = 1;
        for(int j=1;j<=32;++j){
            if(nums[n] & bit) ++count[j-1];
            bit = bit << 1;
        }

        int ans = 0;
        bit = 1;
        for(int j=0;j<32;++j){
            if(count[j] > 0) ans += bit;
            bit = bit << 1;
        }

        return ans;
    }
};
