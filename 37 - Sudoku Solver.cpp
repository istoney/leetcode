/*
 ===================================================================================
 *     File Name: 37 - Sudoku Solver.cpp
 *   Description: https://leetcode.com/problems/soduku-solver/
 *        Author: Stoney
 *      Category: 数独、DFS
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/28
 *      Run Time: 8ms, beats 79.06%
 *     Solutions: DFS：1.首先通过已确定的数字计算每个cell可选的数字（同行、列，九宫中出现
 *                的数字不可以出现），当只有一个可选时确定该cell的数字，直到没有确定数字。
 *                2.选择当前可选数字最少的cell，选择一个可选数字，填入，进行递归；若该数字
 *                结果为false，选择下一数字，若全部可选数字结果都为false，则无解，返回。
 ===================================================================================
 */
#include<iostream>
#include<vector>
#include<set>
#include<bitset>
#include<cmath>
using namespace std;

class Solution {
public:
    int N = 9;
    void solveSudoku(vector<vector<char>>& board) {
        set<int> tmp = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<set<int>> poss(N*N, tmp);

        int count=0;
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                if(board[i][j] != '.'){
                    ++count;
                    poss[i*N+j].clear();
                    updatePoss(poss, i, j, board[i][j]);
                }

        solve(board, poss, count);
    }

    void updatePoss(vector<set<int>> &poss, int i, int j, char ch){
        int pos = ch-'0';
        for(int k=0;k<N;++k){
            //row i
            poss[i*N+k].erase(pos);
            //column j
            poss[k*N+j].erase(pos);
            //row i
            int x = i/3*3+k/3;
            int y = j/3*3+k%3;
            poss[x*N+y].erase(pos);
        }
    }

    bool solve(vector<vector<char>>& board, vector<set<int>> poss, int count){
        int last_cnt = 0;
        while(count != last_cnt){
            last_cnt = count;

            for(int i=0;i<N;++i){
                for(int j=0;j<N;++j){
                    if(board[i][j] == '.'){
                        if(poss[i*N+j].empty()) return false;
                        if(poss[i*N+j].size() == 1){
                            ++count;
                            char intCh = *(poss[i*N+j].begin())+'0';
                            board[i][j] = intCh;
                            updatePoss(poss, i, j, intCh);
                        }
                    }
                }
            }
        }

        if(count == N*N) return true;

		//进行dfs时，每次选取可能性最小的cell填充数字，使可行树最小
        int min = N, min_ind;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                int index = i*N+j;
                if(poss[index].size()>1 && poss[index].size()<min){
                    min = poss[index].size();
					min_ind = index;
                }
            }
        }

		set<int> tmp_set(poss[min_ind]);
		vector<vector<char>> tmp_board(board);

		for(set<int>::iterator it=tmp_set.begin();it!=tmp_set.end();++it){
			poss[min_ind].clear();
			poss[min_ind].insert(*it);
			if(solve(board, poss, count)) return true;
			board = tmp_board;
		}
        return false;
    }
};


int main(){
    Solution s;
    vector<string> v({"1...7..3.","83.6.....","..29..6.8","6....49.7",".9.....5.","3.75....4","2.3..91..",".....2.43",".4..8...9"});
    //vector<string> v({"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."});
    s.solveSudoku(v);
    cout<<"-------------------------------------"<<endl;
    for(int i=0;i<9;++i){
		for(int j=0;j<9;j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
    return 0;
}
