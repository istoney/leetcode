/*
 ===================================================================================
 *     File Name: 67 - Add Binary.cpp
 *   Description: https://leetcode.com/problems/add-binary/
 *        Author: Stoney
 *      Category: 整数的变形表示与操作
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/10
 *      Run Time: 4ms, beats 24.61%
 *     Solutions: 倒序，在最低位加1，并对进位数据循环进位
 ===================================================================================
 */

#include<iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size(), m=b.size();

        if(n==0) return b;
        if(m==0) return a;

        string ans(max(n,m)+1, '0');

        int t = 0;
        int i=n-1, j=m-1, index=max(n,m);
        while(i>=0 || j>=0 || t){
            int tmp = t;
            tmp += i>=0?a[i--]-'0':0;
            tmp += j>=0?b[j--]-'0':0;
            ans[index--] = tmp%2 + '0';
            t = tmp/2;
        }

        index=0;
        while(ans[index]=='0') ++index;

        if(index==max(n,m)+1) return "0";
        return ans.substr(index);
    }
};

int main(){
    Solution s;
    cout<<s.addBinary("0", "0")<<endl;
    return 0;
}
