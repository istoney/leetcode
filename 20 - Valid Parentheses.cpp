/*
 ===================================================================================
 *     File Name: 20 - Valid Parentheses.cpp
 *   Description: https://leetcode.com/problems/valid-parentheses/
 *        Author: Stoney
 *      Category: 括号匹配
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/13
 *      Run Time: 0ms, beats 2.43%
 *     Solutions: 注意判断结束时栈是否为空
 ===================================================================================
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();++i){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                switch(s[i]){
                case ')':
                    if(!st.empty() && st.top()=='(') st.pop();
                    else return false;
                    break;
                case '}':
                    if(!st.empty() && st.top()=='{') st.pop();
                    else return false;
                    break;
                case ']':
                    if(!st.empty() && st.top()=='[') st.pop();
                    else return false;
                    break;
                }
            }
        }

        return st.empty();
    }
};
