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
    TreeNode* bt(vector<int> pre, vector<int> in,int l1,int h1,int l2,int h2){
        if(l1>h1||l2>h2)return nullptr;
        
        int r=pre[l1];
        
        TreeNode  *root=new TreeNode(r);
        //if(l1==h1||l2==h2)return root;
        int mid = 0;
        for(int i =l2;i<=h2;i++){
            if(in[i]==r)break;
            mid++;
        }
        //cout<<r<<" "<<mid<<" "<<l2+mid<<" "<<l1+1+mid<<" "<<l1+1+mid<<endl;
        if(l2+mid<=h2&&l1+mid<=h1){
           // cout<<" ?"<<endl;
            root->left=bt(pre,in,l1+1,l1+mid,l2,l2+mid);
        }
        if(l1+mid+1<=h1){
            root->right=bt(pre,in,l1+mid+1,h1,l2+mid+1,h2);
        }
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len =preorder.size();
        return bt(preorder,inorder,0,len-1,0,len-1);
    }
};
