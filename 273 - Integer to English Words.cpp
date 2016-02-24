/*
 ===================================================================================
 *     File Name: 273 - Integer to English Words.cpp
 *   Description: https://leetcode.com/problems/integer-to-english-words/
 *        Author: Stoney
 *      Category: 整数的变形表示与操作
 *          Note: 101不需要加and
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/11
 *      Run Time: 4ms, beats 74.90%
 *     Solutions:
 ===================================================================================
 */

#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";

        char* T[4][11] = {{"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"},
                   {"","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"},
                   {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"},
                   {"","Hundred"}};
        char* B[4] = {"","Thousand","Million","Billion"};

        int tmp = num;
        int b=0;
        stack<string> st;
        while(tmp){
            int t = tmp%1000;
            string str = "";
            if(t>=100) {
				str+=T[0][t/100]; str += " Hundred";
				t = t%100;
				if(t) str+=" ";
			}
            if(t>=20) {
				str+=T[2][t/10];
				if(t%10) str+=" ";
				str+=T[0][t%10];
			}
            else if(t>=11) {str+=T[1][t%10];}
            else if(t>0) {str+=T[0][t];}

			if(str!=""){
			    st.push(B[b]);
                st.push(str);
			}

            tmp = tmp/1000;
            ++b;
        }

        string ans = "";
        while(!st.empty()){
			ans+=st.top();
			if(st.top()!="") ans+=" ";
			st.pop();
		}
		ans.resize(ans.size()-1);

        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.numberToWords(12345)<<endl;
    return 0;
}
