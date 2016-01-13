/*
 =================================================================================== 
 *     File Name: 3 - Longest Substring Without Repeating Character.cpp
 *   Description: https://leetcode.com/problems/add-two-numbers/
 *        Author: Stoney
 *       Version: 1.0
 *   Submit Time: 2016/01/11
 *      Run Time: 16ms, beats 63.99%
 *     Solutions: ʹ������洢ÿ���ַ��ϴγ��ֵ�λ�ã���255���ַ�������Ҫ��ϣ�� 
 *                �ȳ����ظ��ַ�ʱ(first, second)����first+1��ʼ�������� 
 *                start��¼������ʼλ�ã�С��start�ļ�¼lastֵ��Ч�����ڵ���start
 *                ��lastֵ��Ч�������Ͳ������last��ÿ�δӿ�ʼλ���������� 
 *      Category: �ַ������� 
 =================================================================================== 
 */
 
#include<iostream>
#include<algorithm> 
#include<map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];
        fill(last, last+256, -1);
        int res = 0;
        
        //pos to start search
        int start = 0;
        for(int i=0;i<s.size();i++){
        	if(last[s[i]] >= start){
        		res = max(res, i-start);
        		//update search start pos 
        		start = last[s[i]] + 1;
        	}
			
			//update the new pos of a
			last[s[i]] = i;
        }
        
        //final search from start to N
        return max(res, (int)s.size() - start);
    }
};

int main(){
	Solution s;
	cout<<s.lengthOfLongestSubstring("aaa");
	return 0;
}
