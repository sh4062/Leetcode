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
    vector<int>v1;
    vector<int>v2;
    void inorder1(TreeNode*r){
        if(r->left){inorder1(r->left);}
        if(!r->left&&!r->right)v1.push_back(r->val);
        if(r->right){inorder1(r->right);}
    }
    void inorder2(TreeNode*r){
        if(r->left){inorder2(r->left);}
        if(!r->left&&!r->right)v2.push_back(r->val);
        if(r->right){inorder2(r->right);}
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        inorder1(root1);
        inorder2(root2);
        if(v1.size()!=v2.size())return false;
        for(int i =0;i<v1.size();i++){
            if(v1[i]!=v2[i])return false;
        }
        return true;
    }
};
