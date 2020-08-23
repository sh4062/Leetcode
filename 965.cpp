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
    int a;
    int flag=1;
    void dfs(TreeNode* r){
        
        if(r->val!=a){
            flag=0;
            //cout<<"?"<<endl;
        }
        if(r->left){
            dfs(r->left);
        }
        if(r->right){
             dfs(r->right);
        }
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root)return true;
        a=root->val;
        dfs(root);
        return flag;
    }
};
