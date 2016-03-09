/*
 ===================================================================================
 *     File Name: 142 - Linked List Cycle II.cpp
 *   Description: https://leetcode.com/problems/linked-list-cycle-ii/
 *        Author: Stoney
 *      Category: 数组，重复数字
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/03/04
 *      Run Time: 12ms, beats 20.21%
 *     Solutions: 1.指针fast,slow都指向head，isMove=false,每次fast前移一次，当isMove
 *                为true时前移，slow移动轨迹为[0 1 0 1 0 1...]；
 *                2.设slow经过k步到达cycle_begin，即k个[0 1]，fast此时移动了2k步；
 *                3.fast何时追上slow：
 *                ①fast与slow都在cycle内，则一定是isMove=false，即[0 1 0 1 ... 0]，
 *                设slow从cycle_begin移动了t步，则fast移动了2t+1步，有
 *                (k+2t+1)%N = t%N, 得到t=N-k-1，即fast需要k+1步到达cycle_begin,从head
 *                到cycle_begin需要k步；
 *                ②在cycle_begin相遇：若isMove=true，slow与fast同时前移，相遇，此时fast
 *                移动偶数次；若isMove=false,即为情况①的t=0;
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head, *slow=head, *begin=head;

        bool isMove = false;
        int count = 0;
        while(fast!=NULL){
            fast = fast->next;
            ++count;
            if(isMove) slow = slow->next;
            if(fast==slow) break;

            isMove = !isMove;
        }

        if(fast==NULL) return NULL;
        //情况②，isMove=true
        if(count%2==0) return fast;

        //情况①，情况②，isMove=false
        fast = fast->next;
        while(begin!=fast){
            begin = begin->next;
            fast = fast->next;
        }

        return begin;
    }
};
