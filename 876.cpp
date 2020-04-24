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
    ListNode* middleNode(ListNode*  head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode *slow = head;
        ListNode *fast=head->next;
        while(fast){
            slow = slow->next;
            if(fast->next)
            fast = fast->next->next;
            else break;
        }
        return slow;
        
    }
};