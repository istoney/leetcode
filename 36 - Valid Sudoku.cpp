/*
 ===================================================================================
 *     File Name: 36 - Valid Sudoku.cpp
 *   Description: https://leetcode.com/problems/valid-sudoku/
 *        Author: Stoney
 *      Category: 数组、数独
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/22
 *      Run Time: 12ms, beats 50.84%
 *     Solutions: 遍历枚举
 ===================================================================================
 */

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<string>& board) {
        int N = 9;
        int count[N];

        for(int i=0;i<N;++i){
            memset(count, 0, sizeof(int)*N);
            for(int j=0;j<N;++j){
                char tmp = board[i][j];
                if(tmp=='.') continue;
                //count下标从0开始，so,count[tmp-'1']
                if(tmp>='1' && tmp<='9' && !count[tmp-'1']) count[tmp-'1'] = 1;
                else return false;
            }
        }

        for(int i=0;i<N;++i){
            memset(count, 0, sizeof(int)*N);
            for(int j=0;j<N;++j){
                char tmp = board[j][i];
                if(tmp=='.') continue;
                if(tmp>='1' && tmp<='9' && !count[tmp-'1']) count[tmp-'1'] = 1;
                else return false;
            }
        }

        for(int i=0;i<N;++i){
            memset(count, 0, sizeof(int)*N);
            for(int j=0;j<N;++j){
                int x = i/3*3 + j/3;
                int y = i%3*3 + j%3;
                char tmp = board[x][y];
                if(tmp=='.') continue;
                if(tmp>='1' && tmp<='9' && !count[tmp-'1']) count[tmp-'1'] = 1;
                else return false;
            }
        }

        return true;
    }
};
int main(){
    Solution s;
    vector<string> v({".87654321","2........","3........","4........","5........","6........","7........","8........","9........"});
    cout<<s.isValidSudoku(v)<<endl;
    return 0;
}
