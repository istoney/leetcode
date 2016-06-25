/*
 ===================================================================================
 *     File Name: 54 - Spiral Matrix.cpp
 *   Description: https://leetcode.com/problems/spiral-matrix/
 *        Author: Stoney
 *      Category:
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/05/12
 *      Run Time: 0 ms, beats 7.09%
 *     Solutions: 从(x, x)打印一圈，然后从(x+1, x+1)继续。
 *                每次打印一行或一列，都包含最后一个节点，除了自底向上的一列除外。
 *                只剩最后一行或一列时，注意判断是否会重复打印。
 ===================================================================================
 */

 class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int rows = matrix.size();
        if(rows == 0) return ans;

        int cols = matrix[0].size();
        if(cols == 0) return ans;

        int x=0, y=0;

        while(x<(rows/2 + rows%2) && y<(cols/2 + cols%2)){
            for(int j=y;j<=cols-1-y;++j)
                ans.push_back(matrix[x][j]);

            for(int i=x+1;i<=rows-1-x;++i)
                ans.push_back(matrix[i][cols-1-y]);

            if(rows-1-x > x)    //只剩一行时，放置重复打印该行
                for(int j=cols-2-y;j>=y;--j)
                    ans.push_back(matrix[rows-1-x][j]);

            if(cols-1-y > y)    //只剩一列时，防止重复打印该列 abcd
                for(int i=rows-2-x;i>x;--i)
                    ans.push_back(matrix[i][y]);

            ++x;++y;
        }

        return ans;
    }
};
