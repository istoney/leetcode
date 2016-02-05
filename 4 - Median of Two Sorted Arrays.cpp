/*
 ===================================================================================
 *     File Name: 4 - Median of Two Sorted Arrays.cpp
 *   Description: https://leetcode.com/problems/median-of-two-sorted-arrays/
 *        Author: Stoney
 *       Version: 1.0
 *   Submit Time: 2016/1/31
 *      Run Time: 40 ms, beats 73.77%
 *     Solutions: 1.将问题分解为求第k大的数，若m+n为奇数，求(m+n)/2+1,否则求(m+n)/2和
 *                 (m+n)/2+1，计算平均值
 *                2.求第k大的数：对A、B取第k/2个数，若A[k/2]<B[k/2]，则A[0..k/2]一定
 *                 属于前k个数，可以将A[0..k/2]去除，对余下继续改操作。
 *      Category: 第k大数
 ===================================================================================
 */

#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int N = m + n;
        if(N & 0x1){
            return findKthNum(nums1.begin(), m, nums2.begin(), n, N/2+1);
        } else {
            return (findKthNum(nums1.begin(), m, nums2.begin(), n, N/2)
            + findKthNum(nums1.begin(), m, nums2.begin(), n, N/2+1))/2.0;
        }
    }

    int findKthNum(vector<int>::iterator A, int m, vector<int>::iterator B, int n, int k){
        //make sure m<=n for the convenience of checking whether reach end
        if(m > n) return findKthNum(B, n, A, m, k);
        //check if get the end of A
        if(m == 0) return *(B+k-1);
        if(k == 1) return min(*A, *B);

        //make sure i does not over thr border
        int i=min(k/2, m), j=k-i;
        if(*(A+i-1) < *(B+j-1)) return findKthNum(A+i, m-i, B, n, k-i);
        else if(*(A+i-1) > *(B+j-1)) return findKthNum(A, m, B+j, n-j, k-j);
        else return *(A+i-1);
    }
};

int main(){
    vector<int> A, B;
    A.push_back(1);A.push_back(1);
    B.push_back(1);B.push_back(2);
    Solution s;
    cout<<s.findMedianSortedArrays(A, B)<<endl;
    return 0;
}
