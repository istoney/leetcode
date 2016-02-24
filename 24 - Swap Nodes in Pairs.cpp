/*
 ===================================================================================
 *     File Name: 24 - Swap Nodes in Pairs.cpp
 *   Description: https://leetcode.com/problems/swap-nodes-in-pairs/
 *        Author: Stoney
 *      Category: 链表
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/14
 *      Run Time: 4ms, beats 1.74%
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
    ListNode* swapPairs(ListNode* head) {
        ListNode ans(0);
        ans.next = head;

        ListNode* pre = &ans, *cur = head;
        while(cur!=NULL && cur->next!=NULL){
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = cur;

            cur = pre->next->next->next;
            pre = pre->next->next;
        }

        return ans.next;
    }
};
