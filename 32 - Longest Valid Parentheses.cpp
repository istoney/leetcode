/*
 ===================================================================================
 *     File Name: 32 - Longest Valid Parentheses.cpp
 *   Description: https://leetcode.com/problems/longest-valid-parentheses/
 *        Author: Stoney
 *      Category: 字符串，括号匹配
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/21
 *      Run Time: 16ms, beats 7.33%
 *     Solutions: 栈：栈中存储字符和其位置的pair，遇左括号，则将其压栈，遇到右括号，如果
 *                栈顶是左括号则弹栈，否则压栈。所有字符串中字符处理结束后，栈中剩余的为
 *                不匹配的字符，其位置间隔即为匹配字符串长度。
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/21
 *      Run Time: 12ms, beats 14.25%
 *     Solutions: 基于方法1的改进，在每次弹出时，计算当前位置和栈内上一字符的距离即可
 ===================================================================================
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans =0;
        stack<pair<char, int>> st;
        for(int i=0;i<s.length();++i){
            if(s[i] == '(') st.push(make_pair(s[i], i));
            else{ //')'
                if(!st.empty() && st.top().first=='('){
                    st.pop();
                }
                else st.push(make_pair(s[i], i));
            }
        }

        //(st.top().second, last]
        int last = s.length()-1;
        while(!st.empty()){
            ans = max(ans, last - st.top().second);
            last = st.top().second - 1;
            st.pop();
        }
        ans = max(ans, last+1);

        return ans;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans =0;
        stack<pair<char, int>> st;
        for(int i=0;i<s.length();++i){
            if(s[i] == '(') st.push(make_pair(s[i], i));
            else{ //')'
                if(!st.empty() && st.top().first=='('){
                    st.pop();
                    int start = st.empty() ? -1 : st.top().second;
                    ans = max(ans, i-start);
                }
                else st.push(make_pair(s[i], i));
            }
        }

        return ans;
    }
};
