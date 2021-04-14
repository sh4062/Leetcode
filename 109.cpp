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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        else if(head->next == nullptr) return new TreeNode(head->val);
        ListNode*pre=head;
        ListNode* s=head->next;
        ListNode* f=head->next;
        while(f->next&&f->next->next){
            f=f->next->next;
            s=s->next;
            pre=pre->next;
        }
        pre->next=nullptr;
        TreeNode *root = new TreeNode(s->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(s->next);

        return root;

    }
};
