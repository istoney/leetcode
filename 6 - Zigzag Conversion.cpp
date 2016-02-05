/*
 ===================================================================================
 *     File Name: 6 - Zigzag Conversion.cpp
 *   Description: https://leetcode.com/problems/zigzag-conversion/
 *        Author: Stoney
 *      Category: 字符串转换
 *       Version: 1.0
 *   Submit Time: 2016/02/03
 *      Run Time: 20ms, beats 56.38%
 *     Solutions: 1.首先计算z型排列中每行的字符数，存在数组中；以一个z型为一个实体，对
 *                每一个字符根据其原始序号，计算其在新排序中的行、列号，从而计算总序号
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/03
 *      Run Time: 16ms, beats 74.32%
 *     Solutions: 1.逐行构建新字符串，构建时从原始字符串中的src位置读取字符，放置在新串
 *                之后，添加后src前进step
 *                2.第一行和最后一行的step为n，其他行的step为(numRows-1-i)*2, step2位n-step
 ===================================================================================
*/

#include<cstdio>
#include<iostream>
using namespace std;

// class Solution {
// public:
//     string convert(string s, int numRows) {
//     	if(numRows <= 1) return s;
//
//     	string res = s;
//         int n = numRows*2 - 2;
//
//         int *rowN = new int[numRows];
//         for(int i=0;i<numRows;i++){
//             if(i==0 || i==numRows-1) rowN[i] = s.length()/n;
//             else rowN[i] = (s.length()/n) * 2;
//         }
//         for(int i=0;i<s.length()%n;i++){
//             int r = i<numRows ? i : 2*numRows-2-i;
//             rowN[r]++;
//         }
//         for(int i=1;i<numRows;i++){
//             rowN[i] += rowN[i-1];
//             //cout<<rowN[i-1]<<endl;
//         }
//         //cout<<rowN[numRows-1]<<endl;
//
//         for(int i=0;i<s.length();i++){
//             int c = (i+1)/n, r = (i+1)%n;
//
//             int row, col;
//             if(r == 0){
//             	row = 1;
//             	col = numRows==2 ? c : 2*c;
// 			}
//             else{
//             	r--;
// 				if(r < numRows){
//                 	row = r;
//                     if(r==0 || r==numRows-1) col = c+1;
//                     else col = 2*c+1;
//                 } else {
//                     row = 2*numRows-2-r;
//                     col = 2*c + 2;
//                 }
//             }
//             //cout<<i<<" "<<row<<" "<<col<<endl;
//             if(row) res[rowN[row-1]+col-1] = s[i];
//             else res[col-1] = s[i];
//         }
//
//         delete [] rowN;
//
//         return res;
//     }
// };

class Solution{
public:
    string convert(string s, int numRows){
        if(numRows <= 1) return s;

        string res;
        int n = numRows*2 - 2;
        int size=s.length();

        int src, step, step2;
        for(int i=0;i<numRows;i++){
            src = i;
            if(i==0 || i==numRows-1){
                step = n;
                while(src<size){
                    res.push_back(s[src]);
                    src += step;
                }
            } else {
                step = (numRows-1-i)*2;
                step2 = n-step;
                bool f = 1;
                while(src<size){
                    res.push_back(s[src]);
                    src += f ? step : step2;
                    f = !f;
                }
            }
        }
        return res;
    }
};

int main(){

    string s = "PAYPALISHIRING";
    int n;
    Solution so;
    while(true){
    	cin>>s>>n;
    	cout<<so.convert(s, n);
	}
    return 0;
}
