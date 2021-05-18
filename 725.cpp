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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* r=root;
        int l =0;
        while(r){
            l++;
            r=r->next;
        }
        int c1 = l/k;
        int c2 = l%k;
        ListNode *head = root;
        ListNode *pre = nullptr;
        vector<ListNode*> res(k,nullptr);
        for(int i = 0;i<k;i++){
            res[i]=head;
            int cl = c2>0?c1+1:c1;
            for(int j = 0;j<cl;j++){
                pre=head;
                head=head->next;
            }
            if(pre)pre->next=nullptr;
            if(c2)c2--;

        }
        return res;

    }
};
