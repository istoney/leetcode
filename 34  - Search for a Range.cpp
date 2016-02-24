/*
 ===================================================================================
 *     File Name: 34 - Search for a Range.cpp
 *   Description: https://leetcode.com/problems/search-for-a-range/
 *        Author: Stoney
 *      Category: 数组，查找
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/22
 *      Run Time: 12ms, beats 8.11%
 *     Solutions: 二分：end作为上界，begin-1作为下界
 ===================================================================================
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return vector<int>({-1,-1});

        vector<int>::iterator low, up;
        low = low_bounce(nums.begin(), nums.end(), target);
        up = up_bounce(nums.begin(), nums.end(), target);
        //distance between low and up
        if(up-low < 0) return vector<int>({-1,-1});

        return vector<int>({low-nums.begin(), up-nums.begin()});
    }

    //the first element which >= target
    //return begin if all >= target
    //return end if all < target
    vector<int>::iterator low_bounce(vector<int>::iterator begin, vector<int>::iterator end, int target){
        if(end-begin < 2){
            if(*begin >= target) return begin;
            else return end;
        }

        vector<int>::iterator mid = begin+(end-begin)/2;
        if(*mid>=target){
            if(*(mid-1)<target) return mid;
            else{
                vector<int>::iterator it = low_bounce(begin, mid, target);
                if(it!=mid) return it;
                return end;
            }
        }
        else return low_bounce(mid, end, target);

    }

    //the last element which <= target
    //return begin-1 if all > target
    //return end if <= target
    vector<int>::iterator up_bounce(vector<int>::iterator begin, vector<int>::iterator end, int target){
        if(end-begin < 2){
            if(*begin <= target) return begin;
            else return begin-1;
        }

        vector<int>::iterator mid = begin+(end-begin)/2;
        if(*mid>target){
            if(*(mid-1)<=target) return mid-1;
            else return up_bounce(begin, mid, target);
        }
        else {
            vector<int>::iterator it = up_bounce(mid, end, target);
            if(it!=mid-1) return it;
            return begin-1;
        }
    }
};

int main(){
    Solution s;
    vector<int> v({2, 2});
    s.searchRange(v, 1);
    return 0;
}
