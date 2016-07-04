/*
 ===================================================================================
 *   Description: https://leetcode.com/problems/counting-bits/
 *      Category: bit operation
 *
 *       Version: 1.0
 *   Submit Time: 2016/06/27
 *      Run Time: 92ms, beats 81.07%
 *     Solutions: 采用区间记录int中的0 bit位置，来表示int.
 *                int从0开始自加时，从第0位到第一个0的位置的区间内(区间内全部为1),全部变为0，
 *                原来第一个0的位置变为1，更新操作为O(1)复杂度。
 ===================================================================================
 */

 class Solution {
 public:
     vector<int> countBits(int num) {
         vector<int> ans;

         stack<pair<int, int> > zeros;
         zeros.push(make_pair(0,32));  //position of 0 bits
         int bitsCount = 0;

         for(int i=0;i<=num;++i) {
             ans.push_back(bitsCount);

             //get next number
             pair<int, int> pos = zeros.top();
             zeros.pop();

             ++(pos.first);
             if(pos.first <= pos.second)
                 zeros.push(pos);

             if(pos.first > 1)
                 zeros.push(make_pair(0, pos.first-2));

             bitsCount = bitsCount - pos.first + 2;
         }

         return ans;
     }
 };

//Soulution from discuss
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};
