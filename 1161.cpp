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
    int maxLevelSum(TreeNode* root) {
        int res = 1;
        if(!root)return res;
        int l = 1;
        int curmax=root->val;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int cursum = 0;
            for(int i = q.size();i>0;i--){
                auto tmp = q.front();
                cursum+=tmp->val;
                q.pop();
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
            }
            if(cursum>curmax){
                curmax=cursum;
                res = l;
            }
            l++;
        }

        return res;

    }
};
