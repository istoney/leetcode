/*
 ===================================================================================
 *     File Name: 21 - Merge Two Sorted Lists.cpp
 *   Description: https://leetcode.com/problems/merge-two-sorted-lists/
 *        Author: Stoney
 *      Category: 链表
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/13
 *      Run Time: 8ms, beats 66.39%
 *     Solutions: 在头节点位置的合并比较麻烦，添加空白头结点可以其操作更加简洁。
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        if(l1->val > l2->val) swap(l1, l2);

        ListNode* head = new ListNode(0);
        head->next = l1;

        ListNode* i = l1, *j = l2, *pre=head, *tmp;
        while(j!=NULL){
            while(i!=NULL && i->val<j->val){
                pre = i;
                i=i->next;
            }

            tmp = j; j = j->next;
            pre->next = tmp; tmp->next = i;
            pre = tmp;
        }
        return head->next;
    }
};
