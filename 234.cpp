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
    bool isPalindrome(ListNode* head) {
        if(!head)return true;
        int n=0;
        ListNode* h=head;
        vector<int>v;
        while(h){
            v.push_back(h->val);
            n++;
            h=h->next;
        }
    //    if(n%2!=0)return false;
      //  cout<<n;
        for(int i=0;i<n/2;i++){
            cout<<i;
            if(v[i]!=v[n-i-1])
                return false;
        }
        return true;
    }
};
