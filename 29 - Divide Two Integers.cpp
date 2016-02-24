/*
 ===================================================================================
 *     File Name: 29 - Divide Two Integers.cpp
 *   Description: https://leetcode.com/problems/divide-two-integers/
 *        Author: Stoney
 *      Category: 整数
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/15
 *      Run Time: 8ms, beats 46.71%
 *     Solutions: 1.除法的演算步骤（二进制）：从被除数的最高位开始，选取与除数相同的
 *                位数，即为dvd
 *                2.若dvd大于大于被除数，减去被除数，ans+1；若小于被除数，从被除数中选
 *                取下一位添加到dvd后面，并将ans左移1位。重复该步骤直到被除数最后一位。
 *                      1 2
 *                    _______
 *                17 |2 1 3
 *                    1 7
 *                   ------
 *                      4 3
 ===================================================================================
 */

#include<iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0 || divisor==0) return 0;

        int f = 1, len=0, len2=0;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) f = -1;

        //最复杂在于除数或被除数是-2147483648，其绝对值超出int范围
        //也超出long的范围，必须使用long long
        long long dd, ds, tmp;
        dd = abs((long long)dividend);  //必须先进行类型转换，在abs
        ds = abs((long long)divisor);

        tmp = dd;
        while(tmp > 0){tmp=tmp>>1; ++len;}
        tmp = ds;
        while(tmp > 0){tmp=tmp>>1; ++len2;}

        int index=len-len2;
        long long dvd=dd>>index;    //dd可能是2148473648，因此dvd也能查出int范围
        long long ans=0;
        while(index>=0){
            if(dvd >= ds){
                dvd -= ds;
                ++ans;
            }
            else{
                if(index==0) break;
                dvd = dvd<<1;
				dvd += (dd>>(--index))&0x1;
                ans = ans<<1;
            }
        }

        ans = f==1?ans:-ans;
        //MIN、MAX需要指明是int
        if(ans >= (int)0x7fffffff) return 0x7fffffff;
        if(ans <= (int)0x80000000) return 0x80000000;
        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.divide(-2147483648, -1109186033)<<endl;
    return 0;
}
