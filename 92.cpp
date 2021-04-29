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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyhead=new ListNode(-1);
        dummyhead->next=head;
        ListNode* pre=dummyhead ;
        ListNode* cur ;
        ListNode* tmp ;
        int num = right-left+1;
        int ll = left;
        
        while(--left){
            pre=pre->next;
        }
        if(num==1)return head;
        cur=pre->next;
        while(--num){
            tmp=cur->next;
            cur->next=tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }



        return dummyhead->next;



        


    }
};
