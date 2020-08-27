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
    vector<int>v;
    void inorder(TreeNode* r){
        if(r->left){
            inorder(r->left);
        }
        v.push_back(r->val);
         if(r->right){
            inorder(r->right);
        }
        
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        inorder(root);
        if(v.size()<=1)return true;
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1])
                return false;
            
        }
        return true;
    }
};
