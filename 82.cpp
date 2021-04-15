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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new  ListNode(-1);
        dummy->next=head;
        ListNode*pre=dummy;
        ListNode*cur=dummy->next;
        while(cur&&cur->next){
            //cout<<pre->val<<endl;
            ListNode*curn=cur->next;
            if(cur->val==curn->val){
                while(curn&&curn->val==cur->val){
                    curn=curn->next;
                }
                //cout<<curn->val;
                pre->next=curn;
                cur=curn;
            }else{
                cur=cur->next;
                pre=pre->next;
            }
            
            

        }
        return dummy->next;

    }
};
