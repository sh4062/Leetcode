/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void aux(TreeNode* t1, TreeNode* t2){
        if(t1&&t2){
            //cout<<t1->val;
            t1->val = t1->val + t2->val;
           
        }
         if(t1==nullptr&&t2==nullptr){
            return ;
            
        }
        
        if(t1->left&&t2->left==nullptr){
            ;
        }
        else if(t2->left&&t1->left==nullptr){
            t1->left=new TreeNode(t2->left->val);
            t2->left->val=0;
        }    
         if(t1->right&&t2->right==nullptr){
            ;
        }
       else  if(t2->right&&t1->right==nullptr){
            t1->right=new TreeNode(t2->right->val);
           t2->right->val=0;
            //cout<<t1->right->val;
        }
        if(t1->left&&t2->left){
            aux(t1->left,t2->left);
            
           }
        if(t1->right&&t2->right){
           aux(t1->right,t2->right);
       }
            
        
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==nullptr)return t2;
        if(t2==nullptr)return t1;
        aux(t1,t2);
        return t1;
        
    }
};