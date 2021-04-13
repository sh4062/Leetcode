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
    int widthOfBinaryTree(TreeNode* root) {
        int res = 0;
        int l = 0;
        queue<TreeNode*>q;
        deque<unsigned  long long>q_index;
        q.push(root);
        q_index.push_back(1);
        while(q.size()>0){
        int n = q.size();
                
                for(int j = 0;j<n;j++){
                    TreeNode*tmp = q.front();
                   q.pop();
                   unsigned  long long tmp_index = q_index.front();
                   q_index.pop_front();
                    if(tmp->left){
                    q.push(tmp->left);
                    q_index.push_back(2*tmp_index);
                }
                if(tmp->right){
                    q.push(tmp->right);
                    q_index.push_back(2*tmp_index+1);
                }

                }
                if(q.size()>0)
                res=max(res,int(q_index.back()-q_index.front()));
                l++;
               
                

            }
        
        return res+1;
    }
};
