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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)return head;
        ListNode * root= new ListNode();
        ListNode * tail= new ListNode();
        root->next=head;
        ListNode * p =head;
        int c =1;
        while(p->next){
            p=p->next;
            c++;
        }
        //cout<<c;
        k = k%c;
        c=c-k;
        
        p->next=root->next;
        while(c>1){
            c--;
            head=head->next;
        }
        tail->next=head;
        root->next=head->next;
        head->next=nullptr;
        return root->next;
        
        
    }
};