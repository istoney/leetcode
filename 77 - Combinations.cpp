/*
 ===================================================================================
 *     File Name: 77 - Combinations.cpp
 *   Description: https://leetcode.com/problems/combinations/
 *        Author: Stoney
 *      Category: 数组、组合
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/01
 *      Run Time: 20ms, beats 9.21%
 *     Solutions: DFS:注意重复，如果cand[i]==cand[i-1]，则com+cand[i]将会与com+cand[i-1]重复
 *
 *       Version: 2.0
 *   Submit Time: 2016/03/01
 *      Run Time: 12ms, beats 27.43%
 *     Solutions: 非递归迭代：①若com长度不为k，向尾部添加一个比尾部数大1的数；②若长度为k，将
 *                尾部数加1直到n；③尾部数为n时，弹出，当前尾部数加1.
 ===================================================================================
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> com;
        f(ans, com, n, 1, k);
        return ans;
    }

    void f(vector<vector<int>> &ans, vector<int> com, int N, int n, int k){
        if(!k) ans.push_back(com);
        else{
            for(int i=n;i<=N;++i){
                com.push_back(i);
                f(ans, com, N, i+1, k-1);
                com.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> com({1});

        while(true){
            if(com.size()==k){
                ans.push_back(com);
                if(com.back()==n) {
                    com.pop_back();
                    if(com.empty()) break;
                    com.back() += 1;
                }
                else com.back() += 1;
            }
            else if(com.back()==n){
                com.pop_back();
                if(com.empty()) break;
                com.back() += 1;
            }
            else com.push_back(com.back()+1);
        }

        return ans;
    }
};
