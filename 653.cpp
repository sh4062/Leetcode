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
    set<int> residue;
    bool flag = false;
    void dfs(TreeNode* r,int k){
        if(residue.find(r->val)!=residue.end())flag=true;
        residue.insert(k-r->val);
        if(r->left){
          dfs(r->left,k);
        }
        if(r->right){
          dfs(r->right,k);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root,k);
        return flag;


    }
};
