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
    vector<TreeNode*> v;
    void inorder(TreeNode* r){
        //cout<<r->val;
        v.+push_back(r);
        if(r->right)
        if(r->left)inorder(r->left);
        
         if(r->right)inorder(r->right);
            
    }
    void flatten(TreeNode* root) {
        if(root==nullptr)return;
        inorder(root);
        for(auto &i:v){
            i->left=nullptr;
            i->right=nullptr;
            
        }
        TreeNode*p=root;
        for(int i=1;i<v.size();i++){
           
            p->right=v[i];
            p=p->right;
        }
        
        
    }
};
