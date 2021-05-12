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
    int height(TreeNode* r){
        if(!r)return 0;
        int lv = 0,rv=0;
        if(r->left){
            lv=height(r->left);

        }
        if(r->right){
            rv=height(r->right);
        }
        //cout<<max(lv,rv)+1<<"Q"<<r->val<<endl;
        return max(lv,rv)+1;
    }

    TreeNode* dfs(TreeNode* r){
       if(height(r->left)==height(r->right)){
                return r;
            }
            if(height(r->left)>height(r->right)){
                return dfs(r->left);
            }
            if(height(r->left)<height(r->right)){
                return dfs(r->right);
            }
        return r;

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int h = height(root);
        //cout<<h;
       
        return dfs(root);

    }
};
