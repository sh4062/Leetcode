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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        int l = 0;
        int cnt = 0;
        while(!q.empty()){
            for(int i = q.size();i>0;i--){
            auto tmp =  q.front();
            q.pop();
            int cur=0;
            if(tmp->left){
                if(tmp->left->val==x||tmp->left->val==y){
                    cnt++;
                    cur++;
                }
                q.push(tmp->left);
            }
            if(tmp->right){
                if(!cur&&(tmp->right->val==x||tmp->right->val==y))cnt++;
                q.push(tmp->right);
            }
            if(cnt==2)return true;
            }
            l++;
            cnt=0;
        }
        return cnt==2;
    }
};
