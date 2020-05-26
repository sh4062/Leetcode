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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)return res;
        int m = INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        while(q.size()>1){
            TreeNode* p= q.front();
            q.pop();
            if(p==nullptr){
                res.push_back(m);
                m = INT_MIN;
                q.push(nullptr);
            }
            else{
            //cout<<(p->val);
            m = max(p->val,m);
            if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
            }
        }
        res.push_back(m);
        return res;
        
    }
};