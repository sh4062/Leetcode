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
    int sumOfLeftLeaves(TreeNode* root) {
         if (root==nullptr)
      return 0;
    int ans=0;
    if (root->left!=nullptr&&root->left->left==nullptr&&root->left->right==nullptr)
      ans += root->left->val;
    ans += sumOfLeftLeaves(root->left);
    ans += sumOfLeftLeaves(root->right);
    return ans;
        
    }
};