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
    bool res=false;
    void dfs(TreeNode*r,TreeNode*ss){
        if(r->val==ss->val){
            bool ret1=dfs2(r,ss);
            bool ret2=dfs2(ss,r);
            if(ret1&&ret2)res=true;
        }
        if(r->right){
            dfs(r->right,ss);
        }
        if(r->left){
            dfs(r->left,ss);
        }
        
    }
    bool dfs2(TreeNode*r,TreeNode*s){
        bool ll=true;
        bool rr=true;
        //cout<<s->val<<endl;
        if(r->right){
            if(!s->right)return false;
            rr=dfs2(r->right,s->right);
            
        }
        if(r->left){
            if(!s->left)return false;
            ll=dfs2(r->left,s->left);
            
        }
        if(r&&s&&r->val==s->val&&ll&&rr){
            return true;
        }else{
            return false;
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        dfs(s,t);
        return res;
    }
};
