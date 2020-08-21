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
    int val=0;
    int su;
    int res=0;
    void pre(TreeNode*r){
        dfs(r,0);
        if(r->left){
            pre(r->left);
        }
        if(r->right){
            pre(r->right);
        }
    }
    void dfs(TreeNode*r,int a){
        if(!r)return;
        a+=r->val;
        if(a==su)res++;
        if(r->left){
            dfs(r->left,a);
        }
        if(r->right){
            dfs(r->right,a);
        }
    }
    int pathSum(TreeNode* root, int sum) {
        if(root==nullptr)return 0;
        su=sum;
        pre(root);
        return res;
    }
};
