/*
 ===================================================================================
 *     File Name: 48 - Rotate Image.cpp
 *   Description: https://leetcode.com/problems/rotate-image/
 *        Author: Stoney
 *      Category: 数组
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/03
 *      Run Time: 4ms, beats 7.76%
 *     Solutions: 设顺时针位置为1，2，3，4，交换位置1、3，交换位置1、4，交换位置2、3
 *                1 2
 *                4 3
 ===================================================================================
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int r = n/2;
        int R = r + n%2;


        for(int x=0;x<R;++x){
            for(int y=0;y<r;++y){
                //1
                //int tmp = matrix[x][y];
                //1 <-- 4
                //matrix[x][y] = matrix[n-1-y][x];
                //4 <-- 3
                //matrix[n-1-y][x] = matrix[n-1-x][n-1-y];
                //3 <-- 2
                //matrix[n-1-x][n-1-y] = matrix[y][n-1-x];
                //2 <-- 1
                //matrix[y][n-1-x] = tmp;

                //set position number as:
                // 1 2
                // 4 3
                //swap(1, 3);
                swap(matrix[x][y], matrix[n-1-x][n-1-y]);
                //swap(1, 4)
                swap(matrix[x][y], matrix[n-1-y][x]);
                //swap(2, 3)
                swap(matrix[y][n-1-x], matrix[n-1-x][n-1-y]);
            }
        }
    }
};
