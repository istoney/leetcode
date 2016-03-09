/*
 ===================================================================================
 *     File Name: 242 - Valid Anagrams.cpp
 *   Description: https://leetcode.com/problems/valid-anagrams/
 *        Author: Stoney
 *      Category: 字符串、集合
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/03
 *      Run Time: 12ms, beats 53.02%
 *     Solutions: 以数组保存字符串中每个字符的出现次数，并记录总的次数，然后进行匹配；
 ===================================================================================
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        int key[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int count = 0;
        for(int i=0;i<s.size();++i){
            ++key[s[i]-'a'];
            ++count;
        }

        for(int i=0;i<t.size();++i){
            if(key[t[i]-'a']){
                --key[t[i]-'a'];
                --count;
            }
        }

        return !count;
    }
};
