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
    int res=0;
    void dfs(TreeNode* r,int prev,int len){
        if(!r)return ;
        res=max(res,len);
        //上次左边
        if(prev>0){
            dfs(r->right,-1,len+1);
            dfs(r->left,1,1);
        }
        //上次右边
        if(prev<0){
           dfs(r->left,1,len+1);
           dfs(r->right,-1,1);
        }
        
        //cout<<ret<<endl;
        
    }

    int longestZigZag(TreeNode* root) {
         dfs(root,1,0);
         dfs(root,-1,0);
        return (res);

    }
};
