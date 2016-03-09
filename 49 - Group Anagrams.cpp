/*
 ===================================================================================
 *     File Name: 49 - Group Anagrams.cpp
 *   Description: https://leetcode.com/problems/group-anagrams/
 *        Author: Stoney
 *      Category: 字符串、哈希、排序
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/03
 *      Run Time: 72ms, beats 69.60%
 *     Solutions: 对字符串排序，然后作为同类的key，放入map中；最后对同类进行排序；
 ===================================================================================
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> M;
        for(int i=0;i<strs.size();++i){
            string key = strs[i];
            sort(key.begin(), key.end());
            M[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto it=M.begin();it!=M.end();++it){
            vector<string> v = it->second;
            sort(v.begin(), v.end());
            ans.push_back(v);
        }
        return ans;
    }
};
