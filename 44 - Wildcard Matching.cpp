/*
 ===================================================================================
 *     File Name: 44 - Wildcard Matching.cpp
 *   Description: https://leetcode.com/problems/wildcard-matching/
 *        Author: Stoney
 *      Category: 字符串，模式匹配，动态规划
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/02
 *      Run Time: 491ms, beats 35.87%
 *     Solutions: 动态规划：bool数组创建时需要手动初始化！！！
 *
 *       Version: 2.0
 *   Submit Time: 2016/03/02
 *      Run Time: 16ms, beats 73.70%
 *     Solutions: 双指针遍历：p中遇到*时，记录该位置（p的下一位置p_last，s的当前位置s_last），继续匹配；
 *                若匹配失败，回滚到此处，p回到p_last，s回到s_last+1,再次尝试
 ===================================================================================
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[2][p.size()+1];
        dp[0][0] = true;
        //手动初始化数组
        for(int j=1;j<=p.size();++j){
        	if(p[j-1]=='*') dp[0][j] = dp[0][j-1];
            else dp[0][j]=false;
		}

        for(int i=1;i<=s.size();++i){
            //dp[i][0]可能为1，手动初始化为0
        	dp[i%2][0] = false;
            for(int j=1;j<=p.size();++j){
                if(p[j-1]=='*') dp[i%2][j] = dp[(i-1)%2][j-1]||dp[i%2][j-1]||dp[(i-1)%2][j];
                else if(p[j-1]=='?') dp[i%2][j] = dp[(i-1)%2][j-1];
                else dp[i%2][j] = (s[i-1]==p[j-1]) && dp[(i-1)%2][j-1];
            }
        }

        return dp[s.size()%2][p.size()];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0, j=0;
        int s_last=0, p_last=0;

        /**
        * a*bc              a*bc*bc
        * abbcbcbcbcbc      abbcbcbcbcbc
        */
        while(i<s.size()){
            //j到结尾是，有可能是*，若不是返回false
            if(j==p.size()){
                if(p_last) {j=p_last;i=++s_last;}
                else return false;
            }
            else if((p[j]=='?') || (s[i]==p[j])) {++i;++j;}
            else if(p[j]=='*') {s_last=i;p_last=++j;}
            else if(p_last) {j=p_last;i=++s_last;}
            else return false;
        }

        while(p[j]=='*' && j<p.size()) ++j;

        return j==p.size();
    }
};


int main(){
    Solution s;
    cout<<s.isMatch("aaa","aa")<<endl;
    return 0;
}
