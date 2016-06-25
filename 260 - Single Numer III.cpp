#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        if (nums.size() <= 2) return result;

        int p = 0;
        for (int i=0; i<nums.size(); ++i)
            p = p^nums[i];

        int index = 0;
        while ((p&0x1) == 0){
            p = p >> 1;
            ++index;
        }

        int r1 = 0;
        int r2 = 0;
        for (int i=0; i<nums.size(); ++i){
            if (((nums[i]>>index) & 0x1) == 0x0){
                r1 = r1 ^ nums[i];
            }
            else {
                r2 = r2 ^ nums[i];
            }
        }

        result.push_back(r1);
        result.push_back(r2);
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums({-1, 0});
    s.singleNumber(nums);
    return 0;
}
