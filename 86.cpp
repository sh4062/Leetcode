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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyHead1 = new ListNode(0);
        ListNode* dummyHead2 = new ListNode(0);
        ListNode* node1 = dummyHead1;
        ListNode* node2 = dummyHead2;
        while(head){
            if(head->val<x){
                node1->next = head;
                head = head->next;
                node1=node1->next;
                node1->next=nullptr;

            }else{
                node2->next = head;
                head = head->next;
                node2=node2->next;
                node2->next=nullptr;
            }
        }
        node1->next=dummyHead2->next;
        return dummyHead1->next;
    }
};
