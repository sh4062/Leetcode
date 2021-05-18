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
    int numComponents(ListNode* head, vector<int>& nums) {
        int res = 0;
        unordered_set<int>s;
        for(auto i:nums)s.insert(i);
        while(head){

            if(s.count(head->val)){
                if(!head->next||s.count(head->next->val)==0){
                    res++;
                }
                
            }
            head=head->next;
        }
        return res;

    }
};
