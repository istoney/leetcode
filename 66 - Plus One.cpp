/*
 ===================================================================================
 *     File Name: 66 - Plus One.cpp
 *   Description: https://leetcode.com/problems/plus-one/
 *        Author: Stoney
 *      Category: 整数的变形表示与操作
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/10
 *      Run Time: 4ms, beats 2.66%
 *     Solutions: 倒序，在最低位加1，并对进位数据循环进位
 ===================================================================================
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(n==0) return vector<int>(1,1);

        int tmp = digits[n-1] + 1;
        digits[n-1] = tmp%10;
        int t = tmp/10;

        int index=n-2;
        while(t){
            if(index == -1){
                digits.insert(digits.begin(), t);
                break;
            } else {
            	int tmp = digits[index]+t;
            	digits[index--] = tmp%10;
            	t = tmp/10;
			}
        }

        return digits;
    }
};

int main(){
    vector<int> v(1, 9);
    Solution s;
    s.plusOne(v);
    return 0;
}
