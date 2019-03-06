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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag=0;
        int sum=0;
        ListNode *dummyHead = new ListNode(0);
        ListNode* res=dummyHead,*p,*a=l1,*b=l2;
        while(a||b){
            int x = (a != NULL) ? a->val : 0;
            int y = (b != NULL) ? b->val : 0;
            sum=x+y+flag;
            flag=0;
            if(sum>=10){
                flag=1;
                sum=sum%10;
            }
       
            res->next= new ListNode(sum) ;
            sum=0;
            res=res->next;
            if (a != NULL) a=a->next;
            if (b != NULL) b=b->next;
            //cout<<1;
        }
        if(flag==1){
            res->next= new ListNode(1) ;
            res=res->next;
        }
            
        return dummyHead->next;
    }
};
