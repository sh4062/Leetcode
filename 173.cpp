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
class BSTIterator {
public:
    vector<int> seq;
    void dfs(TreeNode* r){
        if(r->left){
            dfs(r->left);
        }
        seq.push_back(r->val);
        if(r->right){
            dfs(r->right);
        }
        
    }
    int index=0;
    BSTIterator(TreeNode* root) {
        dfs(root);
        index=0;

    }
    
    int next() {
        index++;
        return seq[index-1];
        

    }
    
    bool hasNext() {
        return index<seq.size();

    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
