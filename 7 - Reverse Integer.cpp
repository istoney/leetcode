/*
 ===================================================================================
 *     File Name: 7 - Reverse Integer.cpp
 *   Description: https://leetcode.com/problems/reverse-integer/
 *        Author: Stoney
 *      Category: 正数翻转
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/03
 *      Run Time: 12ms
 *     Solutions: 1.区分正负数，将负数转换为正数处理；res乘以10，加x对10取余，并判断
 *                相加之后是否会超出int范围，若超出，返回0
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/03
 *      Run Time: 8ms, beats 39.16%
 *     Solutions: 1.定义结果类型为long，对x逐步取余，得出结果；返回时判断res是否超出
 *                int范围，若超出，则返回0，否则返回正确结果。
 ===================================================================================
*/

#include<cstdio>
#include<iostream>
using namespace std;

// class Solution {
// public:
//     int reverse(int x) {
//         //负数的最小值，无法转化成正数
//     	if(x==0x80000000) return 0;
//         int f = 1;
//         if(x < 0){
//             f = -1;
//             x = -x;
//             cout<<x<<endl;
//         }
//         int res = 0;
//
//         if(x < 10) res = x;
//         else {
//             int c, r;
//             int max_10 = 0x7fffffff/10;
//             int max_1 = 10 - 0x7fffffff%10;
//             while(x){
//                 r = x%10;
//                 x = x/10;
//                 if(res > max_10 || (res==max_10 && r>=max_1)){
//             		res = 0;break;
// 				}
//                 res = res*10 + r;
//             }
//         }
//
//         return f*res;
//     }
// };

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while(x){   //bool(-1) is true
            //-14/10 = -1 ... -4
            res = res*10 + x%10;
            x = x/10;
        }

        //需要将0x80000000、0x7fffffff放在int中，若直接将res与0x80000000比较，
        //就会将0x80000000装换成long进行运算
        int MIN = 0x80000000, MAX = 0x7fffffff;
        if(res<MIN || res>MAX) return 0;
        else return (int)res;
    }
};

int main(){
    Solution s;
    int t;
    while(true){
        cin>>t;;
        cout<<"----"<<s.reverse(t)<<endl;
    }
    return 0;
}
