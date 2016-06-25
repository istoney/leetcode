/*
 ===================================================================================
 *     File Name: 52 - N-Queens II.cpp
 *   Description: https://leetcode.com/problems/n-queens-ii/
 *        Author: Stoney
 *      Category: 递归
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/05/12
 *      Run Time: 0ms, beats 86.05%
 *     Solutions: 递归遍历所有可能放置的方式，并维护一个位置表，保存每一列、y=x方向、y=-x
 *                方向上各个位置的可用性。
 ===================================================================================
 */

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        if(n <= 0) return ans;

        vector<int> col_flag(n, 1);
        vector<int> pos_flag(2*n-1, 1);
        vector<int> neg_flag(2*n-1, 1);
        solve(0, n, ans, col_flag, pos_flag, neg_flag);

        return ans;
    }

private:
    void solve(int row, int n, int &ans, vector<int>& col_flag, vector<int>& pos_flag, vector<int>& neg_flag){
        if(row == n){
            ++ans;
            return;
        }

        for(int col=0;col<n;++col){
            if(col_flag[col] && pos_flag[row-col+n-1] && neg_flag[row+col]){
                col_flag[col] = pos_flag[row-col+n-1] = neg_flag[row+col] = 0;
                solve(row+1, n, ans, col_flag, pos_flag, neg_flag);
                col_flag[col] = pos_flag[row-col+n-1] = neg_flag[row+col] = 1;
            }
        }
    }
};
