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
    unordered_map<TreeNode *,int> map;

    int res=0;
    int dfs(TreeNode* r,int a){
        int l1=0,l2=0,l3=0,r1=0,r2=0,r3=0;
        if(r==nullptr)return a;
         if(map.count(r))
            return map[r];
        if(r->left){
              l1=dfs(r->left,a);
              l2=dfs(r->left->left,a);
              l3=dfs(r->left->right,a);
        }
        if(r->right){
             r1=dfs(r->right,a);
             r2=dfs(r->right->left,a);
             r3=dfs(r->right->right,a);
            
        }
        //cout<<a;
        //cout<<l2+l3+r2+r3;
        //cout<<r1+l1<<endl;
        int ret= max(l1+r1,l2+l3+r2+r3+r->val);
        map[r]=ret;
       // cout<<ret;
        res=max(res,ret);
        return ret;
        
        
    }
    int rob(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};
