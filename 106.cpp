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
        TreeNode* bt(vector<int> in, vector<int> post,int l1,int h1,int l2,int h2){
        if(l1>h1||l2>h2)return nullptr;
        
        int r=post[h2];
        
        TreeNode  *root=new TreeNode(r);
        if(l1==h1||l2==h2)return root;
        int mid = 0;
        for(int i =l1;i<=h1;i++){
            if(in[i]==r)break;
            mid++;
        }
        //cout<<r<<" "<<mid<<" "<<l2+mid<<" "<<l1+1+mid<<" "<<l1+1+mid<<endl;
        if(mid>0){
           // cout<<" ?"<<endl;
            root->left=bt(in,post,l1,l1+mid-1,l2,l2+mid-1);
        }
        if(l1+mid+1<=h1){
            root->right=bt(in,post,l1+mid+1,h1,l2+mid,h2-1);
        }
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len =postorder.size();
        return bt(inorder,postorder,0,len-1,0,len-1);
    }
};
