/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void visit(TreeNode* root,vector<int>& res){
        if(root==nullptr)return;
        res.push_back(root->val);
        if(root->left){
            visit(root->left,res);
        }
        if(root->right){
            visit(root->right,res);
        }
        
        
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        visit(root1,res);
        visit(root2,res);
        sort(res.begin(),res.end());
        return res;
    }
};