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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        bool flag = true;
        int num = 0;
        while(cur){
            cur = cur->next;
            num++;
            if(num>=k){
                flag = false;
                break;
            }
        }
        if(flag){
            return head;
        }else{
            ListNode* tail = head;
            ListNode* pre = head;
            cur = head->next;
            for(int i = 0;i<k-1;i++){
                ListNode* tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }
            tail->next = reverseKGroup(cur,k);
            return pre;
            
            
        }
        
    }
};