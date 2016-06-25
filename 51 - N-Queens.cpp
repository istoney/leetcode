/*
 ===================================================================================
 *     File Name: 51 - N-Queens.cpp
 *   Description: https://leetcode.com/problems/n-queens/
 *        Author: Stoney
 *      Category: 递归
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/05/12
 *      Run Time: 4ms, beats 90.51%
 *     Solutions: 递归遍历所有可能放置的方式，并维护一个位置表，保存每一列、y=x方向、y=-x
 *                方向上各个位置的可用性。
 ===================================================================================
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> ans;
        if(n <= 0) return ans;

        vector<string> board(n, string(n, '.'));
        vector<int> col_flag(n, 1);
        vector<int> pos_flag(2*n-1, 1);
        vector<int> neg_flag(2*n-1, 1);
        solve(0, n, board, ans, col_flag, pos_flag, neg_flag);

        return ans;
    }

private:
    void solve(int row, int n, vector<string> &board, vector<vector<string>> &ans, vector<int>& col_flag, vector<int>& pos_flag, vector<int>& neg_flag){

        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;++col){
            if(col_flag[col] && pos_flag[row-col+n-1] && neg_flag[row+col]){
                col_flag[col] = pos_flag[row-col+n-1] = neg_flag[row+col] = 0;
                board[row][col] = 'Q';
                solve(row+1, n, board, ans, col_flag, pos_flag, neg_flag);
                board[row][col] = '.';
                col_flag[col] = pos_flag[row-col+n-1] = neg_flag[row+col] = 1;
            }
        }
    }
};

int main(){
    Solution s;
    s.solveNQueens(9);
    return 0;
}
