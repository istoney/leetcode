/*
 ===================================================================================
 *     File Name: 43 - Multiply Strings.cpp
 *   Description: https://leetcode.com/problems/multiply-strings/
 *        Author: Stoney
 *      Category: 整数的变形表示与操作
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/10
 *      Run Time: 8ms, beats 50.39%
 *     Solutions: 对两个字符串倒序遍历，逐个进行相乘计算
 ===================================================================================
 */

#include<iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size(), m=num2.size();
        if(n==0 || m==0) return "0";

        string ans(n+m, '0');

        for(int i=n-1;i>=0;--i){
            int index=m+i;
            int t=0;

            for(int j=m-1;j>=0;--j){
                int p = (num1[i]-'0')*(num2[j]-'0');
                int tmp = t+p+ans[index]-'0';

                ans[index--] = tmp%10+'0';
                t = tmp/10;
            }

            while(t){
                int tmp = t+ans[index]-'0';
                ans[index--] = tmp%10+'0';
                t = tmp/10;
            }
        }

        int index=0;
        while(ans[index]=='0'){++index;}
        if(index==m+n) return "0";
        return ans.substr(index);
    }
};

int main(){
    Solution s;
    cout<<s.multiply("0", "0")<<endl;
    return 0;
}
