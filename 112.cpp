/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//查找路径 递归寻找即可
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        if(root->left==NULL&&root->right==NULL&&sum-root->val==0)return true;
        if(root->left==NULL&&root->right==NULL&&sum-root->val!=0)return false;
        bool b1 = false,b2 = false;
        if(root->left)
         b1 = hasPathSum(root->left,sum-root->val);
        if(root->right)
         b2 = hasPathSum(root->right,sum-root->val);
        return b1||b2;
    }
};