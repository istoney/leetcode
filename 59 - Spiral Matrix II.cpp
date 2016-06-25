/*
 ===================================================================================
 *     File Name: 59 - Spiral Matrix II.cpp
 *   Description: https://leetcode.com/problems/spiral-matrix-ii/
 *        Author: Stoney
 *      Category:
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/05/18
 *      Run Time: 4ms, beats 6.43%
 *     Solutions: 1.每个环的开始位置为(x, y)，其中x,y相等，即左上角；
 *                2.定义环的边界，[x, n-1-x], [y, n-1-y];
 *                3.定义移标(i,j)，从开始位置(x,y)移动，先进行i自加，j自加，i自减，j自减
 *                  操作，操作时不能超过边界;
 *                4.每次操作切换时需要跳入下一位置。
 ===================================================================================
 */

 class Solution {
 public:
     vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>> ans(n, vector<int>(n, 0));
         int num = 1;

         int x=0, y=0;
         int i=0, j=0;

         while(x < (n/2+n%2)){
             int xleft = x, xright=n-1-x;
             int yup=y, ydown=n-1-y;

             i = x; j = y;

             while(i <= xright){
                 ans[j][i] = num++;
                 ++i;
             }
             --i;

             ++j;   //跳入下一位置
             while(j <= ydown){
                 ans[j][i] = num++;
                 ++j;
             }
             --j;

             --i;   //跳入下一位置
             while(i >= xleft){
                 ans[j][i] = num++;
                 --i;
             }
             ++i;

             --j;   //跳入下一位置
             while(j > yup){
                 ans[j][i] = num++;
                 --j;
             }
             ++j;

             ++x; ++y;
         }

         return ans;
     }
 };
