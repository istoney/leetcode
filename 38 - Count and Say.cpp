/*
 ===================================================================================
 *     File Name: 38 - Count and Say.cpp
 *   Description: https://leetcode.com/problems/count-and-say/
 *        Author: Stoney
 *      Category: 字符串
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/28
 *      Run Time: 0ms, beats 69.03%
 *     Solutions: 从第一个字符串开始，迭代计算第n个字符串，O(n^2)
 ===================================================================================
 */
 class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";

        string ans = "1";
        for(int i=1;i<n;++i){
            string tmpStr = "";
            int count = 1;
            char ch = ans[0];
            for(int j=1;j<ans.length();++j){
                if(ans[j]==ch) ++count;
                else{
                    char tmp[64];
                    sprintf(tmp, "%d", count);
                    tmpStr += tmp;
                    tmpStr += ch;

                    count = 1;
                    ch = ans[j];
                }
            }

            char tmp[64];
            sprintf(tmp, "%d", count);
            tmpStr += tmp;
            tmpStr += ch;

            ans = tmpStr;
        }

        return ans;
    }
};
