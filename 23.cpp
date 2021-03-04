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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr; 
        if(lists.size()==1)return lists[0]; 
        //priority_queue<ListNode*, vector<ListNode*>,  [](ListNode*a,ListNode*b){return a->val<b->val;}> pri_queue;
        auto cmp = [](ListNode*a,ListNode*b){return a->val>b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pri_queue(cmp);
        for(auto i:lists){
            if(i)
            pri_queue.push(i);
        }
        ListNode dummy(-1);
        ListNode*res=&dummy;
        
        while(!pri_queue.empty()){
            res->next=pri_queue.top();
            pri_queue.pop();
            res = res->next;
            if(res->next){
                pri_queue.push(res->next);
            }


        }


        return dummy.next;

    }
};
