/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
         ListNode*r0=list1;
         ListNode*r1=list1;
         int aa = a;
         int bb =b;
         while(--aa){
             r0=r0->next;

         }
         while(bb--){
             r1=r1->next;
         }
         r0->next=list2;
         while(r0->next)r0=r0->next;
         //r0=r0->next;
         if(r1->next)r0->next=r1->next;
         return list1;


        
    }
};
