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
    vector<int>res;
        vector<vector<int>> ress;


    int sums;
    int s;
    void dfs(TreeNode*r){
        if(r->left==nullptr&& r->right==nullptr){
            if(sums==s){
                ress.push_back(res);
            }
            return;
        }
        if(r->left){
            sums+=r->left->val;
            res.push_back(r->left->val);
            dfs(r->left);
            sums-=r->left->val;
            res.pop_back();
        }
        if(r->right){
            sums+=r->right->val;
            res.push_back(r->right->val);
            dfs(r->right);
            sums-=r->right->val;
            res.pop_back();
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==nullptr)return ress;
        s=sum;
        res.push_back(root->val);
        sums+=root->val;
        dfs(root);
        return ress;
        
    }
};
