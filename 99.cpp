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
    vector<int>v;
    int l1=0;
    int l2=0;
    void inorder(TreeNode* r){
        if(r->left){inorder(r->left);}
        v.push_back(r->val);
        if(r->right){inorder(r->right);}
    }
    void inorder2(TreeNode* r,int n){
        if(r->left){inorder2(r->left,n+1);}
        if(r->val==v[l2]){r->val=v[l1];l1=l2;}
        if(r->val==v[l1])r->val=v[l2];
        if(r->right){inorder2(r->right,n+1);}
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        vector<int>vv=v;
        sort(vv.begin(),vv.end());
        int i = 0;
        for(i;i<v.size()-1;i++){
            if(vv[i]!=v[i]){
                l1=i;
                break;
            }
        }
        i++;
        for(i;i<v.size();i++){
            if(vv[i]!=v[i]){
                l2=i;
                break;
            }
        }
        inorder2(root,0);
       //cout<<l1<<l2;
    }
};
