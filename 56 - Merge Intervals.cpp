/*
 ===================================================================================
 *     File Name: 56 - Merge Intervals.cpp
 *   Description: https://leetcode.com/problems/merge-intervals/
 *        Author: Stoney
 *      Category: 区间处理
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/05/17
 *      Run Time: 20ms, beats 100%
 *     Solutions: 对所有区间排序，排序规则：start小的在前面，start相等时，end小的在前面
 *                排序后，遍历合并
 ===================================================================================
 */

 /**
  * Definition for an interval.
  * struct Interval {
  *     int start;
  *     int end;
  *     Interval() : start(0), end(0) {}
  *     Interval(int s, int e) : start(s), end(e) {}
  * };
  */
 class Solution {
 public:
     vector<Interval> merge(vector<Interval>& intervals) {
         sort(intervals.begin(), intervals.end(), cmp);

         vector<Interval> ans;
         int i = 0;
         while(i<intervals.size()){
             Interval tmp = intervals[i];

             ++i;
             while(i<intervals.size() && intervals[i].start<=tmp.end){
                 tmp.end = max(tmp.end, intervals[i].end);
                 ++i;
             }
             ans.push_back(tmp);
         }
         return ans;
     }

 private:
     static bool cmp(const Interval &a, const Interval &b){
         if(a.start < b.start) return true;
         if(a.start==b.start && a.end<b.end) return true;
         return false;
     }
 };
