/*
 ===================================================================================
 *     File Name: 9 - Palindrome Number.cpp
 *   Description: https://leetcode.com/problems/palindrome-number/
 *        Author: Stoney
 *      Category: 字符串转换整形
 *          Note: 负数不是回文数
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/03
 *      Run Time: 88ms, beats 42.29%
 *     Solutions: 逐个比较：首先找到x的最高位，然后从最高位开始与最低位进行比较
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/04
 *      Run Time: 76ms, beats 64.64%
 *     Solutions: 1.整数翻转：回文数翻转后应与原整数相等；且不需要完全翻转，只需翻转到中心
 *                位置，剩余部分应与翻转数相等，且有效防止溢出。
 *                2.末尾为0的整数需要特殊处理，如12210，该数不是回文数，但是结果为真
 ===================================================================================
 */

#include<iostream>
using namespace std;


// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x < 0) return false;
//
//         int tmp=1;
//         int x2 = x;
//         while(x2=x2/10) {
//             tmp = tmp*10;
//         }
//
//         int h, t;
//         while(x){
//             h = x/tmp;
//             t = x%10;
//             if(h!=t) return false;
//             x = x%tmp/10;
//             tmp = tmp/100;
//         }
//
//         return true;
//     }
// };

class Solution {
public:
    bool isPalindrome(int x){
        //最后一位如果是0会影响后续的操作
        if(x<0 || (x!=0 && x%10==0)) return false;

        int rev = 0;
        while(x > rev){
            rev = rev*10 + x%10;
            x = x/10;
        }

        return (x==rev) || (rev/10==x);
    }
};

int main(){
    int i = -2147447412;
    Solution s;
    cout<<s.isPalindrome(i)<<endl;
    return 0;
}
