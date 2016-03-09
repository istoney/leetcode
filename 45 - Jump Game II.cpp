/*
 ===================================================================================
 *     File Name: 45 - Jump Game II.cpp
 *   Description: https://leetcode.com/problems/jump-game-ii/
 *        Author: Stoney
 *      Category: 数组，动态规划
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/03
 *      Run Time: 16ms, beats 9.53%
 *     Solutions: 动态规划：dp[n-1]=0，dp[i]=min{dp[i+1]+1,dp[i+2]+1,...,dp[i+len]+1}
 *                len是i位置的跳跃长度；倒序遍历即可。
 ===================================================================================
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[nums.size()];
        dp[nums.size()-1] = 0;

        for(int pos=nums.size()-2;pos>=0;--pos){
            int len = nums[pos];
            int minJump = 0x3fffffff;

            for(int i=len;i>=1;--i){
                if(pos+i>=nums.size()) continue;
                minJump = min(minJump, dp[pos+i]+1);
                //剪枝
                if(minJump <= 2) break;
            }
            dp[pos] = minJump;
        }

        return dp[0];
    }
};

int main(){
    Solution s;
    vector<int> v({1, 2});
    cout<<s.jump(v)<<endl;
    return 0;
}
