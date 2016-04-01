/*
 ===================================================================================
 *     File Name: 69 - Sqrt(x).cpp
 *   Description: https://leetcode.com/problems/sqrtx/
 *        Author: Stoney
 *      Category: 整数，开方
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/22
 *      Run Time: 8ms, beats 39.64%
 *     Solutions: min为1，max为x，进行二分夹逼
 ===================================================================================
 */
class Solution {
public:
    int mySqrt(int x) {
        if(x<=0) return 0;
        long long max = x, min=1, mid;

        while(true){
            if(min >= max-1) return min;
            mid = (max+min)>>1;             //max+min可能会溢出
            long long prd = mid*mid;
            if(prd == x) return mid;
            else if(prd > x) max=mid;
            else min=mid;
        }
    }
};
