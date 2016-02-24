/*
 ===================================================================================
 *     File Name: 42 - Trapping Rain Water.cpp
 *   Description: https://leetcode.com/problems/trapping-rain-water/
 *        Author: Stoney
 *      Category: 数组运算
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/12
 *      Run Time: 8ms, beats 26.61%
 *     Solutions: 如图所示，最高的两个高地（section 1）之间将有积水，并将之间的高地淹没，
 *                因此，计算过程是遍历数组，找出最高的两个高地，计算其间积水，然后对其他
 *                区间section 2，section 3递归计算
 *                         2       1   |    3
 *                             |       |
 *                ----|--------|-------|--------|---
 ===================================================================================
 */

class Solution {
public:
    int trap(vector<int>& height) {
        return f(height.begin(), height.end());
    }

    int f(vector<int>::iterator begin, vector<int>::iterator end){
        if(distance(begin, end)<=1) return 0;

        int first=-1, second=-1;
        vector<int>::iterator firPos, secPos;
        for(vector<int>::iterator it=begin;it!=end;++it){
            if(*it > second){
                second = *it; secPos = it;
                if(second > first){
                    swap(first, second);
                    swap(firPos, secPos);
                }
            }
        }

        if(firPos > secPos){
            swap(first, second);
            swap(firPos, secPos);
        }

        int ans = min(*firPos, *secPos)*(distance(firPos, secPos)-1);
        for(vector<int>::iterator it=firPos+1;it!=secPos;++it){
            ans -= *it;
        }
        if(ans < 0) ans=0;

        return ans+f(begin, firPos+1)+f(secPos, end);
    }
};
