/*
 ===================================================================================
 *     File Name: 137 - Single Number II.cpp
 *   Description: https://leetcode.com/problems/single-number-ii/
 *        Author: Stoney
 *      Category: 数组，查找
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/08
 *      Run Time: 12ms, beats 71.73%
 *     Solutions: ones：当x第一次出现时，ones和twos中都没有x，则ones与x亦或保存x数据，~two
 *                中包含x数据，所以(ones^x) & ~twos可记录x数据；
 *                twos：当ones包含x时，twos就无法保存x，只有当x第二次出现，ones中x消失，
 *                这时twos可以保存x的数据；
 ===================================================================================
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0, twos=0;
        for(int i=0;i<nums.size();++i){
            ones = (ones^nums[i]) & ~twos;
            cout<<ones<<" ";
            twos = (twos^nums[i]) & ~ones;
            cout<<twos<<endl;
        }
        return ones;
    }
};

int main(){
    vector<int> v({3, 3, 5, 5, 1, 3, 5});
    Solution s;
    s.singleNumber(v);
    return 0;
}
