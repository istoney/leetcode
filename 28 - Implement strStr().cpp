/*
 ===================================================================================
 *     File Name: 28 - Implement strStr().cpp
 *   Description: https://leetcode.com/problems/implement-strstr/
 *        Author: Stoney
 *      Category: 字符串子串匹配
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/15
 *      Run Time: 4ms, beats 19.83%
 *     Solutions:
 ===================================================================================
 */

#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int tmp = haystack.size()-n;
        for(int i=0;i<=tmp;++i){
            if(needle.compare(haystack.substr(i, n))==0)
                return i;
        }

        return -1;
    }
};

int main(){
    Solution s;
    cout<<s.strStr("", "a")<<endl;
    return 0;
}
