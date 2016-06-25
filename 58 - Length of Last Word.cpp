/*
 ===================================================================================
 *     File Name: 58 - Length of Last Word.cpp
 *   Description: https://leetcode.com/problems/length-of-last-word/
 *        Author: Stoney
 *      Category: 单词
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/05/17
 *      Run Time: 4ms, beats 1.40%
 *     Solutions: 1.单词：从一个非空字节开始，到一个空字节或者字符串尾部结束；
 *                2.start用来标记单词开始位置，一定为非空，i用来计数单词中的字符数；
 *                3.last_len记录最后一个单词的长度，对一个单词计数成功后才更新last_len
 ===================================================================================
 */

 class Solution {
 public:
     int lengthOfLastWord(string s) {
         int start = 0;
         int last_len = 0;

         while(start < s.length()){
             if(s[start]==' ') {
                 ++start;
                 continue;
             }

             int i=start+1;
             while(i<s.length() && s[i]!=' ') ++i;
             last_len = i - start;
             start = i + 1;
         }

         return last_len;
     }
 };
