/*
 ===================================================================================
 *     File Name: 1 - Two Sum.cpp
 *   Description: https://leetcode.com/problems/two-sum/
 *        Author: Stoney
 *      Category: 两数求和
 *
 *       Version: 1.0
 *   Submit Time: 2016/01/10
 *      Run Time: 12ms, beats 85.88%
 *     Solutions: sort the numbers, and binary search the vector for each number.
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/05
 *      Run Time: 12ms, beats 85.88%
 *     Solutions: 对数组排序，双指针分别指向第一个和最后一个元素，若和小于target，小指
 *                针上移，若和大于target，大指针下移
 ===================================================================================
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int N = nums.size();
//         pair<int, int> nums2[N];
//         for(int i=0;i<N;i++){
//             nums2[i] = make_pair(nums[i], i+1);
//         }
//
//         sort(nums2, nums2+N);
//         vector<int> res;
//         for(int i=0;i<N;i++){
//             pair<int, int> P = nums2[i];
//             int index = b_search(nums2+i, nums2+N, target-P.first);
//             if(index >=0){
//                 res.push_back(min(P.second, index));
//                 res.push_back(max(P.second, index));
//                 return res;
//             }
//         }
//     }
//
//     int b_search(pair<int, int> *begin, pair<int, int> *end, int v){
//         if(begin == end) return -1;
//
//         pair<int, int> *middle = begin + (end - begin)/2;
//         pair<int, int> p = *middle;
//         if(p.first == v) return p.second;
//         else if(p.first < v) return b_search(middle+1, end, v);
//         else return b_search(begin, middle, v);
//     }
//
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        pair<int, int> nums2[nums.size()];
        for(int i=0;i<nums.size();i++){
            nums2[i] = make_pair(nums[i], i);
        }

        sort(nums2, nums2+nums.size());
        int i=0, j=nums.size()-1;
        while(i<=j){
            if(nums2[i].first+nums2[j].first < target) ++i;
            else if(nums2[i].first+nums2[j].first > target) --j;
            else break;
        }

        vector<int> res;
        res.push_back(min(nums2[i].second, nums2[j].second)+1);
        res.push_back(max(nums2[i].second, nums2[j].second)+1);

        return res;
    }
};

int main(){
    Solution s;

    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(11);
    v.push_back(15);
    v = s.twoSum(v, 9);
    cout<<v[0]<<" "<<v[1]<<endl;
    return 0;
}
