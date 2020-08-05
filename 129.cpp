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
#include<string>
class Solution {
public:
    string a="";
    int res=0;
    void dfs(TreeNode* r){
        if(r->left==nullptr&&r->right==nullptr){
            res+=stoi(a);
            
            return ;
        }
        if(r->left){a.push_back(char(r->left->val+'0'));dfs(r->left);a.pop_back();}
        if(r->right){a.push_back(char(r->right->val+'0'));dfs(r->right);a.pop_back();}
        
    }
    int sumNumbers(TreeNode* root) {
        if(root==nullptr)return 0;
        a+=char(root->val+'0');
        dfs(root);
        return res;
    }
};
