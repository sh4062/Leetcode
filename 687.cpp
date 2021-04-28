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
    int ret = 0;
    int dfs(TreeNode* r){
        int res = 1;
        int lv=0,rv=0;
        if(r->left&&r->left->val==r->val){
            lv+=dfs(r->left);
        }
        if(r->right&&r->right->val==r->val){
            rv+=dfs(r->right);
        }
        ret = max(ret,res+lv+rv);
        return max(res+lv,res+rv);

    }
    void inorder(TreeNode* r){
        if(r->left){
            inorder(r->left);
        }
        
        if(r->right){
            inorder(r->right);
        }
        dfs(r);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return 0;
        inorder(root);
        return ret-1;

    }
};
