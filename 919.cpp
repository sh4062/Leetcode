/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    vector<TreeNode*>vv;
    CBTInserter(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            vv.push_back(tmp);
            if(tmp->left)q.push(tmp->left);
            if(tmp->right)q.push(tmp->right);
        }
    }
    
    int insert(int v) {
        TreeNode* cur =new TreeNode(v);
        vv.push_back(cur);
        if(vv[vv.size()/2-1]->left==nullptr){
             vv[vv.size()/2-1]->left=cur;
        }else{
             vv[vv.size()/2-1]->right=cur;
        }
        
        return vv[vv.size()/2-1]->val;
        

    }
    
    TreeNode* get_root() {
        return vv[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
