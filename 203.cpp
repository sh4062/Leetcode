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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* h=head;
        ListNode dummy=ListNode(-1);
        ListNode* pre=&dummy;
        while(h){
            if(h->val==val){
                pre->next =h->next;
                h=h->next;
            }else{
                pre->next=h;
                pre=pre->next;
                h=h->next;
            }
        }
        return dummy.next;

    }
};
