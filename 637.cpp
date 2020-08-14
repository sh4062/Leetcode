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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<TreeNode*>v;
        vector<TreeNode*>child;
        v.push_back(root);
        vector<double> res;
        double s;
        while(v.size()>0){
            s=0;
            for(int i = 0;i<v.size();i++){
                s+=v[i]->val;
                if(v[i]->left)child.push_back(v[i]->left);
                if(v[i]->right)child.push_back(v[i]->right);
            }
            s/=v.size();
            res.push_back(s);
            v=child;
            child.clear();
            
            
        }
        return res;
        
    }
};
