/*
 ===================================================================================
 *     File Name: 55 - Jump Game.cpp
 *   Description: https://leetcode.com/problems/jump-game/
 *        Author: Stoney
 *      Category:
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/05/16
 *      Run Time: 16ms, beats 9.56%
 *     Solutions: 每个位置上可达的位置是一个范围，因此只要可达终点的最小位置，处于该范围
 *                之内（小于右边界，倒序遍历，因此最小可达位置一定大于左边界）
 *
 *       Version: 2.0
 *   Submit Time: 2016/05/16
 *      Run Time: 16ms, beats 9.56%
 *     Solutions: 正序遍历数组，记录当前最远可达位置，遍历可达节点，更新可达位置
 ===================================================================================
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0) return false;

        int minCan = nums.size()-1;

        for(int i=nums.size()-2;i>=0;--i){
            if(minCan <= i+nums[i]){
                minCan = i;
            }
        }

        return minCan==0;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0) return false;

        int max_reach = nums.front();
        if(max_reach >= nums.size()-1) return true;

        for(int i=1;i<nums.size();++i){
            if(i > max_reach) return false;

            max_reach = max(max_reach, i+nums[i]);
            if(max_reach >= nums.size()-1) return true;
        }

        return false;
    }
};
