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
    void dfs(TreeNode* r){
         
        if(r->left){
            if(cOne(r->left)==false){
                r->left=nullptr;
            }
            else dfs(r->left);
        }
         if(r->right){
             if(cOne(r->right)==false){
                r->right=nullptr;
            }
            else
            dfs(r->right);
        }
       
        
    }
    bool cOne(TreeNode* r){
        bool flag = false;
        if(r->val==1)return true;
        if(r->left){
            flag=flag|cOne(r->left);
        }
         if(r->right){
            flag=flag|cOne(r->right);
        }
        return flag;
    }
    TreeNode* pruneTree(TreeNode* root) {
       // bool f=cOne(root->right->left);
        dfs(root);
        if(root->val==0&&root->left==nullptr&&root->right==nullptr){
            root=nullptr;
        }
       // cout<<2<<endl;
        return root;
    }
};
