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
    int res = 0;
    int dfs(TreeNode* r,int maxv){
        
        if(!r)return 0;
        int v = 0;
        if(r->val>=maxv){
            maxv=r->val;
            v++;
        }
        
        
        
       
            v+=dfs(r->left,maxv);
            v+=dfs(r->right,maxv);
  

       
        return v;
    }
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        if(!root->right&&!root->left)return 1;
        res=dfs(root,-9999);
        return res;
        
    }
};
