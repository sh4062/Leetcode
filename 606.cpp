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
    string itos(int s){
        stringstream ss;
        ss<<s;
        return ss.str();
    }
    string s;
    void dfs(TreeNode*  a){
       
        int l=0,r=0;
        s=s+itos(a->val);
        if(a->left){
            l=1;
        s=s+'(';
            }
        if(a->left)dfs(a->left);
         if(l==1)
        s=s+')';
                if(l==0&&a->right){
        s=s+"()";
            }
        if(a->right){
            r=1;
        s=s+'(';
            }
        if(a->right)dfs(a->right);
       
         if(r==1)
        s=s+')';
        
    }
    string tree2str(TreeNode* t) {
         if(!t)return s;
        dfs(t);
        return s;
    }
};
