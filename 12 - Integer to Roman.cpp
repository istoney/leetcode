/*
 ===================================================================================
 *     File Name: 12 - Integer to Roman.cpp
 *   Description: https://leetcode.com/problems/intger-to-roman/
 *        Author: Stoney
 *      Category: 整数的变形表示与操作
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/11
 *      Run Time: 28ms, beats 89.04%
 *     Solutions:
 ===================================================================================
 */

#include<iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        char* T[4][10] = {{"0","I","II","III","IV","V","VI","VII","VIII","IX"},
                          {"0","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                          {"0","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                          {"0","M","MM","MMM"}};

        string ans = "";
        int tmp = num;
        if(tmp>=1000) {ans += T[3][tmp/1000]; tmp = tmp%1000;}
        if(tmp>=100) {ans += T[2][tmp/100]; tmp = tmp%100;}
        if(tmp>=10) {ans += T[1][tmp/10]; tmp = tmp%10;}
        if(tmp>=1) {ans += T[0][tmp/1];}

        return ans;
    }
};
