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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p1 = dummy;
        ListNode* p2 = dummy;
        if(head->next == nullptr) return nullptr;
        for(int i = 0;i<n;i++) {if(p1->next)p1 = p1->next;}
        while(p1->next!=nullptr){
            p1 = p1->next;
            p2 = p2->next;
        }
        p1 = p2->next;
        p2->next = p2->next->next;
        delete (p1);
        return dummy->next;
        
    }
};