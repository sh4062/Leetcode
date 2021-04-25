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
    vector<int> nextLargerNodes(ListNode* head) {
       stack<int> st;
       vector<int> temp;
       while(head!=NULL){
           temp.push_back(head->val);
           head=head->next;  
       } 
       vector<int> res(temp.size(),0); //初始化为0,减少判断
       for(int i=0;i<temp.size();i++){
        while(!st.empty() && temp[st.top()]<temp[i]){
            res[st.top()]=temp[i];
            st.pop();
        }
            st.push(i);
       }
       return res;
    }
};
