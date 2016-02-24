#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int N = 9;
    struct Poss{
        set<int> tmp = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<set<int>> possNum(N*N, tmp);

        struct Cand{bitset<N> c(0x1ff);}
        vector<vector<Cand> > posCand(3*N, vector<Cand>(N));
    }

    void solveSudoku(vector<string>& board) {
        Poss poss;

        int count=0;
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                if(board[i][j] != '.'){
                    ++count;
                    poss.possNum[i*N+j].clear();
                    updatePoss(poss, i, j, board[i][j]);
                }

        solve(board, poss, count);
    }

    void updatePoss(Poss &poss, int i, int j, char ch){
        int pos = ch-'0';
        //row i
        for(int k=0;k<N;++k)
            if(poss.possNum[i*N+k].erase(pos)){
                poss.posCand[i][pos-1].set(k);
                --cand[i][pos-1];
            }
        //column j
        for(int k=0;k<N;++k)
            poss.possNum[k*N+j].erase(pos);
        //row i
        for(int k=0;k<N;++k){
            int x = i/3*3+k/3;
            int y = j/3*3+k%3;
            poss.possNum[x*N+y].erase(pos);
        }
    }

    bool solve(vector<string>& board, vector<set<int>> poss, int count){
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
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                int index = i*N+j;
                if(poss[index].size() > 1){
                    set<int> tmp_set(poss[index]);
                    vector<string> tmp_board(board);

                    for(set<int>::iterator it=tmp_set.begin();it!=tmp_set.end();++it){
                        poss[index].clear();
                        poss[index].insert(*it);
                        if(solve(board, poss, count)) return true;
                        board = tmp_board;
                    }
                    poss[index] = tmp_set;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<string> v({"1...7..3.","83.6.....","..29..6.8","6....49.7",".9.....5.","3.75....4","2.3..91..",".....2.43",".4..8...9"});
    s.solveSudoku(v);
    for(int i=0;i<9;++i){
		for(int j=0;j<9;j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
    return 0;
}
