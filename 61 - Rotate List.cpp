/*
 ===================================================================================
 *     File Name: 61 - Rotate List.cpp
 *   Description: https://leetcode.com/problems/rotate-list/
 *        Author: Stoney
 *      Category: 旋转
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/05/18
 *      Run Time: 12ms, beats 6.31%
 *     Solutions: 1.双指针遍历链表，间隔为k，找到倒数第k个节点；
 *                2.将头节点接在倒数第k个节点后面，形成新链表；
 *                3.k可能大于链表长度，将k对链表长度取余数；
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
     ListNode* rotateRight(ListNode* head, int k) {
         if(head==NULL || k == 0) return head;

         ListNode* pFast=head, *pCur=head, *pPre=NULL;
         int listLen = 0;

         while(pCur!=NULL) {
             ++listLen;
             pCur = pCur->next;
         }
         k = k%listLen;
         if(k == 0) return head;

         pCur = head;
         for(int i=0;i<k && pFast!=NULL;++i) pFast = pFast->next;
         if(pFast == NULL) return head;

         while(pFast!=NULL) {
             pFast = pFast->next;
             pPre = pCur;
             pCur = pCur->next;
         }

         pPre->next = NULL;
         ListNode* pNewHead = pCur;
         while(pCur!=NULL) {
             pPre = pCur;
             pCur = pCur->next;
         }
         pPre->next = head;

         return pNewHead;
     }
 };
