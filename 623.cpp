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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* n = new TreeNode(v);
            n->left = root;
            return n;
        } 
        queue<TreeNode*>q;
        q.push(nullptr);
        q.push(root);
        
        int l = 1;
        while(q.size()>1){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp){
                cout<<tmp->val<<endl;
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                     q.push(tmp->right);

                }

            }else{
                cout<<l<<endl;
                if(l==d-1){
                    while(q.size()>=1){
                    TreeNode* t = q.front();
                    q.pop();
                    cout<<q.size()<<"!!!!!!!!!!!!!!"<<endl;
                    TreeNode* l =new TreeNode(v);
                    TreeNode* ll = t->left;
                    t->left = l;
                    l->left = ll;
                    TreeNode* r =new TreeNode(v);
                    TreeNode* rr = t->right;
                    t->right = r;
                    r->right = rr;
    
                    }
                    return root;

                }
                l++;
                q.push(nullptr);

            }


        }
        return root;

    }
};
