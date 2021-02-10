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
    unordered_map<int,int>mp;
    int dfs(TreeNode* root){
        int i = root->val;
        if(root->left){
            
            i+=dfs(root->left);

        }
        if(root->right){
            
            i+=dfs(root->right);

        }
        mp[i]++;
        return i;

    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        if(!root)return res;
        dfs(root);
        int max_v= 0 ;
        
        for(auto i:mp){
            max_v=max(max_v,i.second);
        }
         for(auto i:mp){
            if(i.second==max_v){
                res.push_back(i.first);
            }
        }
        return res;
        

    }
};
