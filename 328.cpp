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
    ListNode* oddEvenList(ListNode* head) {
        if (!head)return head;
        ListNode*  o=head;
        ListNode* e=head->next;
        ListNode* res=head->next;
        while(o->next&&e->next){
            o->next=e->next;
            o=o->next;
            e->next=o->next;
            e=e->next;
        }
        o->next=res;

        return head;
    }
};
