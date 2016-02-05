/*
 =======================================================================================
 *     File Name: 5 - Longest Palindromic Substring.cpp
 *   Description: https://leetcode.com/problems/longest-palindromic-substring/
 *        Author: Stoney
 *      Category: 回文串
 *
 *       Version: 1.0
 *   Submit Time: 2016/1/31
 *      Run Time: 76 ms, beats 51.18%
 *     Solutions: 暴力枚举：遍历所有字符，以该字符为中心，双指针向两侧延伸寻找回文串。
 *
 *       Version: 2.0
 *   Submit Time: 2016/2/1
 *      Run Time: 8ms, beats 80.38%
 *     Solutions: Manacher算法：
 *                1.在字符串中插入#，包含头尾，使得所有回文串都变成奇数回文串；使用数组p[i]记录
 *                 每个回文串的【半径】， 则回文串的长度为p[i]-1，例如#b#a#b#，#b#a#a#b#
 *                2.越界问题：在字符串头部放置$，因此字符串以$开头，以'\0'结尾，若字符串中不
 *                 存在$和'\0'，则进行比较是达到头尾就会停止，但此方法前提是字符串中不存在$，不
 *                 采用
 *                3.记录最长的p[i]和中心位置index，
 =======================================================================================
 */

#include<cstdio>
#include<iostream>
using namespace std;

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int max = 0;
//         int ptr = 0;
//         for(int i=0;i<s.length();i++){
//             int count = 1;
//             int p = i-1, q = i+1;
//             while(p>=0 && q<s.length() && s[p]==s[q]){
//                 p--,q++;
//                 count+=2;
//             }
//             if(count > max){
//                 max = count;
//                 ptr = p + 1;
//             }
//
//             count = 0;
//             p = i;q = i+1;
//             while(p>=0 && q<s.length() && s[p]==s[q]){
//                 p--,q++;
//                 count+=2;
//             }
//             if(count > max){
//                 max = count;
//                 ptr = p + 1;
//             }
//         }
//
//         return s.substr(ptr, max);
//     }
// };

class Solution{
public:
    string longestPalindrome(string s){
        string s2;
        for(int i=0;i<s.length();i++){
            s2.push_back('#');
            s2.push_back(s[i]);
        }
        s2.push_back('#');

        int max=0, mid, len=0, index=0;
        int p[2010];
        for(int i=0;i<s2.length();i++){
            if(max > i){
                p[i] = min(p[mid*2-i], max-i);
            } else p[i] = 1;

            while(i-p[i]>=0 && i+p[i]<s2.length() && s2[i-p[i]]==s2[i+p[i]]){
                p[i]++;
            }

            if(i+p[i] > max){
                max = i+p[i];
                mid = i;
            }

            if(p[i] > len){
                index = i;
                len = p[i];
            }
        }

        //#a#b#a# 3 4
        if(index & 0x1) return s.substr(index/2-(len-1)/2, len-1);
        //#a#b#b#a# 4 5
        else return s.substr(index/2-(len-1)/2, len-1);
    }
};

int main(){
    string s = "abb";
    Solution so;
    cout<<so.longestPalindrome(s)<<endl;
    return 0;
}
