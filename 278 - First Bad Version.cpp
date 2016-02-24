/*
 ===================================================================================
 *     File Name: 278 - First Bad Version.cpp
 *   Description: https://leetcode.com/problems/first-bad-version/
 *        Author: Stoney
 *      Category: 数组，查找
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/22
 *      Run Time: 0ms, beats 2.18%
 *     Solutions: 二分
 ===================================================================================
 */

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return f(1, n);
    }

    //[begin, end]
    int f(int begin, int end){
        if(begin == end) return isBadVersion(begin)?begin:end;

        //(begin+end)/2 will lead to overflow
        int mid = begin+(end-begin)/2+1;
        if(isBadVersion(mid)){
            //mid shall not be included in two sub-parts
            if(!isBadVersion(mid-1)) return mid;
            else return f(begin, mid-1);
        }
        return f(mid, end);
    }
};
