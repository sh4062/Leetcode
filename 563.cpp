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
    int ll=0;
    int rr=0;
    int t(TreeNode*r){
        //auto a=dfs(r,0);
        //res+=abs(a.first-a.second);
        
        int s=r->val;
        if(r->left){s+=t(r->left);}
        if(r->right){s+=t(r->right);}
        return s;
    }
    void dfs(TreeNode*r){
        int lv=0,rv=0;
        if(r->left){lv=t(r->left);dfs(r->left);}
        if(r->right){rv=t(r->right);dfs(r->right);}
        res+=abs(lv-rv);
    }
    
    int findTilt(TreeNode* root) {
        if(!root)return 0;
        dfs(root);
                                  return res;
    }
};
