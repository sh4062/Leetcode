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
    void inorder(TreeNode* root,TreeNode* &res){
        if(root==nullptr)return;
        if(root->left)inorder(root->left,res);
       
        TreeNode* p = new TreeNode(root->val);
        // cout<<res->val;
        res->right = p;
        res = res->right;
        if(root->right)inorder(root->right,res);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==nullptr) return nullptr;
        TreeNode* res = new TreeNode(root->val);
        TreeNode* p =res;
        inorder(root,p);
        return res->right;
        
    }
};