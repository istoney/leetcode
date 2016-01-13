/*
 =================================================================================== 
 *     File Name: 2 - Add Two Numbers.cpp
 *   Description: https://leetcode.com/problems/add-two-numbers/
 *        Author: Stoney
 *       Version: 1.0
 *   Submit Time: 2016/01/10
 *      Run Time: 36ms, beats 70.83%
 *     Solutions: add the digits one by one alone with the linked list.
 *      Category: 链表 
 =================================================================================== 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0),* cur = res;
        int p = 0;
        
        while(l1 || l2 || p){
            int sum;
            
            if(l1 && l2) sum = l1->val + l2->val + p;
            else if(l1) sum = l1->val + p;
            else if(l2) sum = l2->val + p;
            else sum = p;
            
            p = sum/10;
            sum = sum%10;
            
            cur->next = new ListNode(sum);
            cur = cur->next;
            cur->next = NULL;
            
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        
        return res->next;
    }
};
