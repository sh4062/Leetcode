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
    vector<int>resv;
    void dfs(TreeNode* r){
        if(r->left){
            
            dfs(r->left);
        }
        resv.push_back(r->val);
        if(r->right){
            
            dfs(r->right);
        }
        
    }
    int minDiffInBST(TreeNode* root) {
        if(root==nullptr)return 0;
        dfs(root);
        int res=INT_MAX;
        for(int i =1;i<resv.size();i++){
            res=min(res,resv[i]-resv[i-1]);
        }
        return res;
    }
};
