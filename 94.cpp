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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr)return res;
        stack<TreeNode*>s;
        s.push(root);
        root = root->left;
        while(!s.empty()||root){
            while(root){
                s.push(root);
                root = root->left;
            }
            res.push_back(s.top()->val);
            root = s.top()->right;
            s.pop();
            
        }
        return res;
        
    }
};