/*
 ===================================================================================
 *     File Name: 60 - Permutation Sequence.cpp
 *   Description: https://leetcode.com/problems/permutation-sequence/
 *        Author: Stoney
 *      Category: 排列
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/05/18
 *      Run Time: 0ms, beats 40.22%
 *     Solutions: 1.第一个排列为 1,2,3..n;
 *                2.将1与i交换，则跳过(i-1)*factorial[n-1]个排列，即3,1,2..n是第2*factorial[n-1]个排列；
 *                3.选择第一个大于k的factorial[i],将1与1+i交换，k则变为k%factorial[i];
 *                4.递归处理；
 ===================================================================================
 */

 class Solution {
 public:
     string getPermutation(int n, int k) {
         int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

         string perm = "123456789";
         perm.resize(n);

         --k;   //求第k个，应该将k减1，k为0时停止
         int i = 0;
         while(k){
             if(k < factorial[n-i-1]){
                 ++i; continue;
             }

             swap(perm[i], perm[i + k/factorial[n-i-1]]);
             k = k%factorial[n-i-1];

             ++i;
             sort(perm.begin()+i, perm.end());
         }

         return perm;
     }
 };
