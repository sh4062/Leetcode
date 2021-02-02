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
    vector<TreeNode*>res;
    unordered_map<string,int>hash;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
    string dfs(TreeNode* root){
        if(!root)return "";
        string cur = to_string(root->val)+"l"+dfs(root->left)+"r"+dfs(root->right);
        //cout<<cur<<endl;
        if(hash[cur]==1){
            res.push_back(root);
        }
        hash[cur]++;
        return cur;
    }
};
