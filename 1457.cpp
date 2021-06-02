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
    int curs[10]={0};
    int res = 0;
    void dfs(TreeNode* r){
        ++curs[r->val];
        if(r->left){
            dfs(r->left);
        }
        if(r->right){
            dfs(r->right);
        }
        if(!r->left&&!r->right){
            int cnt = 0;
            for(auto i:curs){
                if(i%2!=0)cnt++;
                
            }

            if(cnt<2)res++;

        }
        --curs[r->val];
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return res;

    }
};
