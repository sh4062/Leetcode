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
    vector<TreeNode*>gt(int s,int e){
        if(s>e){
          return {nullptr};
        }
        vector<TreeNode*>trees;
        for(int i =s;i<=e;i++){
            vector<TreeNode*>lt = gt(s,i-1);
            vector<TreeNode*>rt = gt(i+1,e);
            for(auto &l:lt){
                for(auto &r:rt){
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left = l;
                    currTree->right = r;
                    trees.emplace_back(currTree);
                }
            }
        }

        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(!n){
            return {};
        }
        return gt(1,n);

    }
};
