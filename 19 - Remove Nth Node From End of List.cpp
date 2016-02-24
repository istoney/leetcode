/*
 ===================================================================================
 *     File Name: 19 - Remove Nth Node From End of List.cpp
 *   Description: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *        Author: Stoney
 *      Category: 链表
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/13
 *      Run Time: 4ms, beats 20.38%
 *     Solutions:
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N = 0, i=0;
        ListNode * cur = head;
        for(;cur!=NULL;cur=cur->next) ++N;

        if(n>N || n<0) return head;

        if(n==N){
            cur = head->next;
            delete head;
            return cur;
        }

        cur = head;i=0;
        for(;cur!=NULL;cur=cur->next){
            if(++i+n==N){
                ListNode* next = cur->next;
                cur->next = next->next;
                delete next;
                return head;
            }
        }
    }
};
