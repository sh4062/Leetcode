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
    void reorderList(ListNode* head) {
        if(head==nullptr)return;
        if(head->next==nullptr)return;
        vector<ListNode*>v;
        //ListNode* root = new ListNode(0,head);
        ListNode* tail=head;
        ListNode*p=head;
        int cnt = 0;
        while(tail->next){
            v.push_back(tail);
            tail=tail->next;
            
            cnt++;
        }
        if(tail){v.push_back(tail);
                }
        int cnt2=1;
       // head->next=v[3];
        while(cnt>cnt2){
            //cout<<cnt<<cnt2;
            p->next=v[cnt];
            if(cnt2<cnt){//&&p->next!=nullptr
                
                //cout<<p->next->val;
                //cout<<cnt2;
            p->next->next=v[cnt2];
                p=p->next->next;
                }else{
                p=p->next;
            }
            
           
            cnt2+=1;
            cnt-=1;
           // p->next->next->next=nullptr;
            if(cnt<cnt2){
                //p->next=nullptr;
                p->next=nullptr;
            }
            if(cnt==cnt2){
                //p->next=nullptr;
                p->next->next=nullptr;
            }
            //p=p->next;
            //cout<<p->val<<endl;
            
            
       }
        //delete root;
        
    }
};
