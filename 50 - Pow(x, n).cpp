/*
 ===================================================================================
 *     File Name: 50 - Pow(x, n).cpp
 *   Description: https://leetcode.com/problems/powx-n/
 *        Author: Stoney
 *      Category: 浮点数，幂计算
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/022
 *      Run Time: 4ms, beats 9.12%
 *     Solutions: ans初始值设为x，每次迭代使ans平方，直到ans小于等于Pow(x,n)的最大，
 *                将剩余的次数用递归方式计算。
 ===================================================================================
 */

class Solution {
public:
    double myPow(double x, int n) {
        return rec(x, n);
    }

    //几个特殊的测试数据需要注意：
    //3.33  2147483647  第一次二分计算，剩余部分继续递归，再次二分
    //3.33  1           递归结束
    //3.33  -3          注意幂为负数
    //3.33  -2147483648 幂数转换为整数后溢出，使用long long
    double rec(double x, long long n){
        if(n < 0) return 1.0/rec(x, -n);
        if(n==1) return x;

        double ans = x;
        long long count = 1;

        //n = 2147483647
        //then count got 1073741823
        while(count <= n/2){
            ans = ans*ans;
            count *= 2;
        }

        //for the rest, cal in recursion
        return ans*rec(x, n-count);
    }
};
