/*
 ===================================================================================
 *   Description: https://leetcode.com/problems/text-justification/
 *      Category: greedy
 *
 *       Version: 1.0
 *   Submit Time: 2016/06/23
 *      Run Time: 24ms, beats 16.42%
 *     Solutions: 贪心，注意每一行的最后
 ===================================================================================
 */

 class Solution {
 public:
     vector<string> fullJustify(vector<string>& words, int maxWidth) {
         vector<string> ans;
         if(words.size()==0)
             return ans;

         int start=0, length = 0;

         for(int i=0;i<words.size();++i) {
             length += words[i].length();

             //this line's length is equals to maxWidth
             if(length == maxWidth) {
                 string tmp;
                 for(int j=start;j<=i;++j) {
                     tmp += words[j];
                     if(j!=i) tmp += " ";
                 }
                 ans.push_back(tmp);

                 start = i+1;
                 length = 0;
             }
             else if(length > maxWidth) {
                 length = length - words[i].length() - 1;

                 string tmp;
                 //just one word in this line
                 if(i == start+1) {
                     tmp += words[start];
                     tmp += string(maxWidth-length, ' ');
                 }
                 else {
                     int spaceWidth = (maxWidth-length)/(i-start-1);
                     int rmd = (maxWidth-length) % (i-start-1);

                     for(int j=start;j<i;++j) {
                         tmp += words[j];
                         if(j!=i-1)
                             tmp += string(spaceWidth+(j-start<rmd ? 2 : 1), ' ');
                     }
                 }

                 ans.push_back(tmp);

                 start = i;
                 length = 0;
                 --i;
             }
             else ++length;
         }

         if(start < words.size()) {
             string tmp;
             for(int j=start;j<words.size();++j) {
                 tmp += words[j];
                 if(j!=words.size()-1) tmp += " ";
             }

             tmp += string(maxWidth-tmp.length(), ' ');
             ans.push_back(tmp);
         }

         return ans;
     }
 };
