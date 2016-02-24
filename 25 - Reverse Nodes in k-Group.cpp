/*
 ===================================================================================
 *     File Name: 25 - Reverse Nodes in k-Group.cpp
 *   Description: https://leetcode.com/problems/reverse-nodes-in-k-group/
 *        Author: Stoney
 *      Category: 链表
 *          Note:
 *
 *       Version: 1.0
 *   Submit Time: 2016/02/14
 *      Run Time: 28ms, beats 7.63%
 *     Solutions: 首先查找到第k个节点，顺序将1、2、3...k-1的节点插入到第k节点后面
 *
 *       Version: 2.0
 *   Submit Time: 2016/02/14
 *      Run Time: 24ms, beats 40.48%
 *     Solutions: 1.基于方法1改进，不需要首先找到第k个节点在进行插入。
 *                2.找到本段开始的前置节点pre，从第二个开始插入到pre节点之后，执行k-1次
 *                3.结束时，第一个节点成为本段的尾节点，cur是下一段的开始，需要将其连接
 *                以k=4为例：
 *                开始：pre -> 1 -> 2 -> 3 -> 4 -> 5
 *                将2插入pre之后：pre -> 2 -> 1 -> 3 -> 4 -> 5
 ===================================================================================
 */

 #include<iostream>
 using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(k<2) return head;
//
//         ListNode ans(0);
//         ans.next = head;
//
//         ListNode* pre=&ans, *kPtr, *tmp, *newPre;
//         int count=0;
//         while(pre->next){
//             kPtr = pre->next; count = 1;
//             while(count<k && kPtr!=NULL){ kPtr = kPtr->next;++count;}
//
//             if(!kPtr) break;
//             //翻转后第一个节点成为第k个，即下一次的pre
//             newPre = pre->next;
//
//             //所有节点插入到kPtr后面，kPtr始终指向同一节点
//             while(--count>0){
//                 tmp = pre->next;
//                 pre->next = pre->next->next;
//
//                 tmp->next = kPtr->next;
//                 kPtr->next = tmp;
//             }
//
//             pre = newPre;
//         }
//
//         return ans.next;
//     }
// };


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

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
     ListNode* reverseKGroup(ListNode* head, int k) {
         if(k<2) return head;

         ListNode ans(0);
         ans.next = head;

         ListNode* pre=&ans, *cur, *tmp, *newPre;
         int count;
         while(pre->next){
             newPre = pre->next;//结束后第一个节点成为尾，也是下一段的pre
             cur = pre->next->next;
             count=1;
             while(cur && count<k){
                 tmp = cur;
                 cur = cur->next;

                 tmp->next = pre->next;
                 pre->next = tmp;
                 ++count;
             }
             //结束后cur指向下一段的第一个节点，或者NULL
             //插入操作中第一个节点(newPre)始终指向节点2，需要使其指向下一节点，否则会形成环
             newPre->next = cur;

             if(--count<k-1){ //roll back
                 newPre = pre->next;
                 cur = pre->next->next;
                 while(cur && count){
                     tmp = cur; cur = cur->next;

                     tmp->next = pre->next;
                     pre->next = tmp;
                     --count;
                 }
                 newPre->next = cur;//同上，否则会使结果中形成环，导致TLE
                 return ans.next;
             }

             pre = newPre;
         }

         return ans.next;
     }
 };

int main(){
    Solution s;
    ListNode l(1);
    l.next = new ListNode(2);
    s.reverseKGroup(&l, 3);
    return 0;
}
