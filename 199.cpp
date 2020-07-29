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
    vector<int> rightSideView(TreeNode* root) {
        
        if(root==nullptr)return {};
        vector<int> res;
//         vector<TreeNode *>p;
//         vector<TreeNode*>child;
        
//         p.push_back(root);
//         while(!p.empty()){
//             res.push_back(p[p.size()-1]->val);
//             //cout<<p[p.size()-1]->val;
//             for(auto i:p){
//                 if(i->left){
//                     child.push_back(i->left);
//                 }
//                 if(i->right){
//                     child.push_back(i->right);
//                 }
//             }
//             p=child;
//             child.clear();
//         }
        queue<TreeNode*>q;
        q.push(root);
        //q.push(nullptr);
        while(q.size()>0){
            
//             if(p==nullptr){
//                 res.push_back(tmp);
//                 q.push(nullptr);
                
//             }else{
            int size=q.size();
            while(size){
                               
                auto p=q.front();
            
                q.pop();
               // cout<<tmp;
                if(p->left){
                    q.push(p->left);
                    
                }if(p->right){
                    q.push(p->right);
                }
                if(size==1)
                    res.push_back(p->val);
                size--;
            }
            
        }
        // res.push_back(tmp);
        return res;
        
    }
};