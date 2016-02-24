/*
 ===================================================================================
 *     File Name: 53 - Maximum Subarray.cpp
 *   Description: https://leetcode.com/problems/maximum-subarray/
 *        Author: Stoney
 *      Category: 数组运算
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/12
 *      Run Time: 24ms, beats 2.10%
 *     Solutions: 1.二分法：将数组二分，则最大和子序列将出现在左半部分、右半部分，或者跨越
 *                分界，由两边的一部分组成。
 *                2.对于跨越边界的情况，从分界分别向左、向右遍历整个数组，计算所有遍历数字
 *                的和，记录最大值
 *                3.出现左右半部分的情况，递归计算即可。
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/12
 *      Run Time: 8ms, beats 75.43%
 *     Solutions: 1.和最大子序列，即从任意位置开始向前计算最大和的最大值，倒序就是以任意
 *                位置为结尾的和最大子序列，max{max{sum(k,i), i=1..n, k=1..i+1}}
 *                2.计算以位置i截至的和最大子序列，假设A[1..i-1]的结果已知，推广A[1..i]
 *                的结果①出现在A[1..i-1]中，②以A[i]为结尾的子序列。
 ===================================================================================
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return f(nums.begin(), nums.end());
    }

    int f(vector<int>::iterator begin, vector<int>::iterator end){
        if(distance(begin, end)==1) return *begin;

        vector<int>::iterator mid = begin+distance(begin,end)/2-1;
        int ans = 0;

        int sumMax=0x80000000, sum=0;
        for(vector<int>::iterator it=mid;distance(begin,it)>=0;--it){
            sum += *it;
            sumMax = max(sumMax, sum);
        }
        ans += sumMax;

        sumMax=0x80000000; sum=0;
        for(vector<int>::iterator it=mid+1;it!=end;++it){
            sum += *it;
            sumMax = max(sumMax, sum);
        }
        ans += sumMax;

        ans = max(ans, f(begin, mid+1));
        ans = max(ans, f(mid+1, end));

        return ans;
    }
};

class Solution2 {
public:
    /*
    * 从头遍历数组，对遍历过的数字求和，若和小于等于0，记为一段，重复该步骤
    * 1.整分段和为0或负，2.从最后一个元素开始的倒序非完整分段和为负
    * 因此这些分段对于后面构造子串无益
    */
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], tmp=nums[0];
        for(int i=1;i<nums.size();++i){
            //以i为结尾的和最大子序列
            if(tmp>0) tmp+=nums[i];
            else tmp=nums[i];

            //全局和最大子序列
            ans = max(ans, tmp);
        }
        return ans;
    }
};
