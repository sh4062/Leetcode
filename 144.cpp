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
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr)return res;
        stack<TreeNode*>s;
        s.push(root);
        res.push_back(root->val);
        root = root->left;
        while(!s.empty()||root){
            while(root){
                res.push_back(root->val);
                s.push(root);
                root = root->left;
            }
            
            root = s.top()->right;
            s.pop();
            
        }
        return res;
        
    }
};