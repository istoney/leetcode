/*
 ===================================================================================
 *     File Name: 8 - String to Integer (atoi).cpp
 *   Description: https://leetcode.com/problems/string-to-integer-atoi/
 *        Author: Stoney
 *      Category: 字符串转换整形
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/03
 *      Run Time: 12ms
 *     Solutions: 需要处理的情况：开头的空格、正负号、溢出、无效输入
 *                1.若字符串为空，返回0
 *                2.首先循环去除开头的空格，若去除空格后为空，返回0
 *                3.若字符串以-开头，设置标志f为-1，若+则f为1，最后返回ans*f
 *                4.计算时根据f判断是否本次计算会使其溢出，若溢出则返回MIN或MAX
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/04
 *      Run Time: 8ms, beats 68.10%
 *     Solutions: 主要优化在于溢出的判断：正数的溢出临界为2147483647(0x7fffffff)，负数
 *                的溢出临界为2147483648(0x80000000)，所以当ans大于2147483647时即为溢出
 *                然后根据f返回MIN或MAX
 ===================================================================================
 */

#include<cstdio>
#include<iostream>
using namespace std;

//class Solution {
//public:
//    int myAtoi(string str) {
//        if(str.length()==0) return 0;
//
//        int f = 1, i = 0;
//        int ans = 0;
//
//        while(str[i]==' ' && i<str.length()) i++;
//        if(i==str.length()) return 0;
//
//        if(str[i]=='-'){
//            i++;
//            f = -1;
//        }
//        else if(str[i] == '+')
//            i++;
//
//        int MIN=0x80000000, MAX=0x7fffffff;
//        cout<<f<<endl;
//        for(;i<str.length();i++){
//            if('0'<=str[i] && str[i]<='9'){
//                if(f==1){
//                	if(ans>MAX/10 || (ans==MAX/10 && (str[i]-'0')>7) ) return MAX;
//				}
//                else{
//                	if(ans>MAX/10 || (ans==MAX/10 && (str[i]-'0')>8) ) return MIN;
//				}
//                ans = ans*10 + str[i]-'0';
//            } else break;
//        }
//
//
//        if(f*ans < MIN) return MIN;
//        else if(f*ans > MAX) return MAX;
//        else return f*ans;
//    }
//};

class Solution {
public:
    int myAtoi(string str) {
        if(str.length()==0) return 0;

        int f = 1, i = 0, ans = 0;
        while(str[i]==' ' && i<str.length()) i++;
        if(i==str.length()) return 0;

        if(str[i]=='-'){
            i++;
            f = -1;
        }
        else if(str[i] == '+'){
            i++;
        }

        int MAX_10 = 0x7fffffff/10;
        while('0'<=str[i] && str[i]<='9'){
            if(ans>MAX_10 || (ans==MAX_10 && (str[i]-'0')>7)){
                if(f==1) return 0x7fffffff;
                else return 0x80000000;
            }
            ans = ans*10 + str[i++]-'0';
        }

        return f*ans;
    }
};
int main(){
	Solution s;
	cout<<s.myAtoi("1")<<endl;
	return 0;
}
