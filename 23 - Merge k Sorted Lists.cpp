/*
 ===================================================================================
 *     File Name: 23 - Merge k Sorted Lists.cpp
 *   Description: https://leetcode.com/problems/merge-k-sorted-lists/
 *        Author: Stoney
 *      Category: 链表
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/13
 *      Run Time: 420ms, beats 48.20%
 *     Solutions: 优先队列：将链表头放入优先队列，逐个节点添加到新队列中
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head, *tmp, *l;

        priority_queue<ListNode*, vector<ListNode*>, comparator> Q;
        for(int i=0;i<lists.size();++i)
            if(lists[i]!=NULL)
                Q.push(lists[i]);

        while(!Q.empty()){
            l = Q.top(); Q.pop();
            tmp = l; l = l->next;
            cur->next = tmp;
            tmp->next = NULL;
            cur = cur->next;

            if(l!=NULL) Q.push(l);
        }

        return head->next;
    }

    class comparator{
    public:
        bool operator() (const ListNode* l1, const ListNode* l2){
            return l1->val > l2->val;
        }
    };
};
