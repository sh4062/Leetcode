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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int res = 0;
        queue<int>s;
        q.push(root);
        q.push(nullptr);
        while(q.size()>1){
            TreeNode*p=q.front();
            q.pop();
            if(p==nullptr){
                res=s.front();
                //cout<<res;
               while (!s.empty()) s.pop();
               q.push(nullptr);

            }else{
                //cout<<p->val;
                s.push(p->val);
                if(p->left)q.push(p->left);
                    if(p->right)q.push(p->right);
            }
        }
             return s.front();
        }
   
    
};