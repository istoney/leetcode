/*
 ===================================================================================
 *     File Name: 13 - Roman to Integer.cpp
 *   Description: https://leetcode.com/problems/roman-to-integer/
 *        Author: Stoney
 *      Category: 整数的变形表示与操作
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/10
 *      Run Time: 60ms, beats 41.08%
 *     Solutions:
 * Roman numeral (n)    I   IV  V   IX  X   XL  L   XC  C   CD  D   CM  M
 * Decimal value (v)    1   4   5   9   10  40  50  90  100 400 500 900 1000
 ===================================================================================
 */
 
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> table;
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;

        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;++i){
            int t = table[s[i]];
            if(i==n-1){
                ans += t;
                continue;
            }

            if( (s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X'))
             || (s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C'))
             || (s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M')))
            {
                ans -= table[s[i]];
                ans += table[s[i+1]];
                ++i;
            }
            else{
                ans += t;
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.romanToInt("MDCCCLXXXIV")<<endl;
    return 0;
}
