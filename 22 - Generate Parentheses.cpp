/*
 ===================================================================================
 *     File Name: 22 - Generate Parentheses.cpp
 *   Description: https://leetcode.com/problems/generate-parentheses/
 *        Author: Stoney
 *      Category: 括号匹配
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/13
 *      Run Time: 4ms, beats 13.27%
 *     Solutions: 生成准则：①第i个右括号前面至少有i个左括号；②所有左括号总数量为n
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/13
 *      Run Time: 4ms, beats 13.27%
 *     Solutions: 非递归
 *
 *       Version: 3.0
 *   Submit Time: 2016/02/13
 *      Run Time: 0ms, beats 34.91%
 *     Solutions: n对括号，共有2n个位置，每个位置上有两种可能性。通过左右括号的数量和
 *                对称性计算判断某位置上出现左右括号的可能性。
 ===================================================================================
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(ans, "", n, 1, 0);
        return ans;
    }

    /*
     * rIndex: 右括号的index
     * lNum：前面左括号的数量
    */
    void f(vector<string> &v, string prefix, int n, int rIndex, int lNum){
        if(rIndex==n){
            //if(lNum < n-1) return;
            if(lNum == n-1) prefix += "(";
            v.push_back(prefix+")");
        }
        else {
            if(lNum < rIndex){
                prefix+="(";
                ++lNum;
            }

            for(lNum;lNum<=n;++lNum){
                f(v, prefix+")", n, rIndex+1, lNum);
                prefix += "(";
            }
        }
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        struct Paras {
            string prefix;
            int rIndex, int lNum;
            Paras(string p, int r, int l):prefix(p),rIndex(r),lNum(l) {}
        };

        vector<string> ans;
        stack<Paras> st;
        st.push(Paras("", 1, 0));
        while(!st.empty()){
            Paras p = st.top();
            st.pop();

            if(p.rIndex==n){
                if(lNum == n-1) p.prefix += "(";
                ans.push_back(p.prefix+")");
            }
            else {
                if(lNum < rIndex){
                    p.prefix+="(";
                    ++p.lNum;
                }

                for(;p.lNum<=n;++p.lNum){
                    st.push(Paras(p.prefix+")", p.rIndex+1, p.lNum));
                    p.prefix += "(";
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        //该位置的左右括号的可能性
        //根据括号对称性，如果还有未对称的左括号，就可以是左括号
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        //只要还未出现n个左括号，就可以是左括号
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }
};
