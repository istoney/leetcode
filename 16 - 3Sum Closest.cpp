/*
 ===================================================================================
 *     File Name: 16 - 3Sum Closest.cpp
 *   Description: https://leetcode.com/problems/3sum-closest/
 *        Author: Stoney
 *      Category: 整数求和
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/06
 *      Run Time: 24ms, beats 23.13%
 *     Solutions: 类似3Sum，对数组排序后遍历，选取数字作为第一个数字，对其后的范围进行
 *                twoSum计算；计算中记录距离target最近的结果。
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/09
 *      Run Time: 12ms, beats 52.35%
 *     Solutions: 基于方法1的改进，在进行twoSum计算时，采取二分查找，快速查找到目标位置
 ===================================================================================
 */

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());
//
//         int ans = nums[0] + nums[1] + nums[2];
//         for(int i=0;i<nums.size()-2;++i){
//             int front=i+1, back=nums.size()-1;
//             while(front < back){
//                 int sum = nums[i]+nums[front]+nums[back];
//                 if(abs(sum-target) < abs(ans-target))
//                     ans=sum;
//                 if(sum<target) ++front;
//                 else if(sum>target) --back;
//                 else break;
//             }
//         }
//
//         return ans;
//     }
// };
//
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        if(nums.size()==3) return ans;

        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size()-2;++i){
            int new_target = target - nums[i];
            int front=i+1, back=nums.size()-1;
            while(front < back){
                int sum = nums[i]+nums[front]+nums[back];
                if(sum==target) return target;

                if(abs(sum-target) < abs(ans-target))
                    ans=sum;
                //lower_bound find the first element which not less than
                //upper_bound find the first element which greater than
                if(sum<target){
                    vector<int>::iterator it = lower_bound(nums.begin()+front+1, nums.begin()+back, new_target-nums[back]);
                    if(nums.begin()+back==it){
                        //no result found in the range, then the last(back-1) maybe the Closest
                        if(front==back-1) ++front;
                        else front=back-1;
                    }
                    //should't just search for the number greater or equal to it
                    //--it maybe the closest
                    else if(nums.begin()+front+1==it)
                        front=distance(nums.begin(), it);
                    else front=distance(nums.begin(), it)-1;
                }
                else if(sum>target){
                    vector<int>::iterator it = lower_bound(nums.begin()+front+1, nums.begin()+back, new_target-nums[front]);
                    //查找失败时，范围内的值可能全部大于目标，也可能全部小于目标
                    if(nums.begin()+back==it) --back;
                    else back=distance(nums.begin(), it);
                }
                else break;
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(8);
    v.push_back(16);
    v.push_back(32);
    v.push_back(64);
    v.push_back(128);

    cout<<s.threeSumClosest(v, 82)<<endl;
    return 0;
}
