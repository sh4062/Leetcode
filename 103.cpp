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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)return res;
        deque<TreeNode* > p;
        deque<TreeNode* > child;
        p.push_back(root);
        int i = 0;
        while(p.size()>0){
           for(int i = 0;i<p.size();i++){
            auto tmp = p[i];
            if(tmp->left){
                child.push_back(tmp->left);
            }
                if(tmp->right)
                child.push_back(tmp->right);
            }
                vector<int>tmpv;
              if(i%2==0){
            for(const auto i:p)
             tmpv.push_back(i->val);
              }else{
                  while(p.size()>0){
                      
                      tmpv.push_back(p[p.size()-1]->val);
                      p.pop_back();
                      }
                  }
             
          // cout<<p.size()<<endl;
            p=child;
            child.clear();
        res.push_back(tmpv);
            i++; }
        
    return res;
    }
};
