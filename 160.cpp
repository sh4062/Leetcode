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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA;
        ListNode* b=headB;
        int la=0;
        int lb=0;
        while(a){
            la++;
            a=a->next;
        }
        while(b){
            lb++;
            b=b->next;
        }
        
        int dif = abs(lb-la);
        //cout<<dif;
        if(la>lb){
            while(dif--){
                headA=headA->next;
            }
        }else{
            while(dif--){
                headB=headB->next;
            }
        }
        while(headB!=headA  ){
            headA=headA->next;
            headB=headB->next;
        }
        return headB;
        
    }
};
