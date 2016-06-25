/*
 ===================================================================================
 *     File Name: 57 - Insert Interval.cpp
 *   Description: https://leetcode.com/problems/insert-interval/
 *        Author: Stoney
 *      Category: 区间处理
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/05/17
 *      Run Time: 20ms, beats 100%
 *     Solutions: 新建一个空vector，比较newInterval和intevals元素大小，选择插入；
 *                newInterval插入时判断是否可以与上一元素合并，以及其后元素是否可以合并
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
     vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
         vector<Interval> ans;
         bool inserted = false;

         for(int i=0;i<intervals.size();++i){
             if(!inserted){
                 if(cmp(intervals[i], newInterval)) ans.push_back(intervals[i]);
                 else {
                     if(!ans.empty() && ans.back().end>=newInterval.start)
                         ans.back().end = max(ans.back().end, newInterval.end);
                     else ans.push_back(newInterval);
                     inserted = true;
                     --i;   //将newInterval插入，i不需要后移
                 }
             }
             else if(!ans.empty() && ans.back().end>=intervals[i].start)
                 ans.back().end = max(ans.back().end, intervals[i].end);
             else {
                 ans.insert(ans.end(), intervals.begin()+i, intervals.end());
                 break;
             }
         }

         if(!inserted){     //newInterval插入时，判断是否可以与上一元素合并
             if(!ans.empty() && ans.back().end>=newInterval.start)
                 ans.back().end = max(ans.back().end, newInterval.end);
             else ans.push_back(newInterval);
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
