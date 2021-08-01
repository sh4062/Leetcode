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
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* dummy=new ListNode(-1);
        // dummy->next = head;
        ListNode* cur = head;
        ListNode* pre =dummy;
        // ListNode*tmp;
        while(head){
            cur = dummy;
            while(cur->next&&cur->next->val<head->val)cur=cur->next;
            pre = head;
            head=head->next;
            pre->next = cur->next;
            cur->next=pre;
           
        }

        return dummy->next;
 
    }
};
