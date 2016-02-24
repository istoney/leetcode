/*
 ===================================================================================
 *     File Name: 11 - Container with Most Water.cpp
 *   Description: https://leetcode.com/problems/container-with-most-water/
 *        Author: Stoney
 *      Category: 数组运算
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/11
 *      Run Time: 24ms, beats 54.16%
 *     Solutions: 双指针指向数组头尾，计算当前面积，并更新最大面积，然后将较小的指针移动
 *                如下图，若height[1]<height[n-1],则对于任意整数p (1<p<n-1),
 *                Area(1,n-1) > Area(1,p). 因为若height[p]>height[1], Area(1,p)=
 *                heigh[1]*(p-1)<Area(1,n-1), 若height[p]<height[1],...
 *                所以，Area(1,p) (1<p<n-1)不需要计算
 *                 1               p      n-1
 *                -|---------------|-------|-
 ===================================================================================
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;

        int i=0, j=height.size()-1;
        while(i<j){
            int tmp = min(height[i], height[j])*(j-i);
            ans = max(ans, tmp);
            if(height[i]<height[j]) ++i;
            else --j;
        }
        return ans;
    }
};
