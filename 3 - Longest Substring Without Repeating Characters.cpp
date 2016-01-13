/*
 =================================================================================== 
 *     File Name: 3 - Longest Substring Without Repeating Character.cpp
 *   Description: https://leetcode.com/problems/add-two-numbers/
 *        Author: Stoney
 *       Version: 1.0
 *   Submit Time: 2016/01/11
 *      Run Time: 16ms, beats 63.99%
 *     Solutions: 使用数组存储每个字符上次出现的位置，共255个字符，不需要哈希表 
 *                等出现重复字符时(first, second)，从first+1开始重新搜索 
 *                start记录搜索开始位置，小于start的记录last值无效，大于等于start
 *                的last值有效，这样就不必清空last和每次从开始位置重新搜索 
 *      Category: 字符串操作 
 =================================================================================== 
 */
 
#include<iostream>
#include<algorithm> 
#include<map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];
        fill(last, last+256, -1);
        int res = 0;
        
        //pos to start search
        int start = 0;
        for(int i=0;i<s.size();i++){
            if(last[s[i]] >= start){
                res = max(res, i-start);
                //update search start pos 
                start = last[s[i]] + 1;
            }
            //update the new pos of a
            last[s[i]] = i;
        }
        
        //final search from start to N
        return max(res, (int)s.size() - start);
    }
};

int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("aaa");
    return 0;
}
