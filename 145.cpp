/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode *root)
    {

        //         if(root==nullptr)return res;
        //         else{
        //             postorderTraversal(root->left);
        //             postorderTraversal(root->right);
        //             res.push_back(root->val);

        //         }
        //         return res;
        if (root == nullptr)
            return res;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *pre = nullptr;
        while (!s.empty())
        {
            root = s.top();
            if ((!root->left && !root->right) ||
                (pre && (pre == root->left || pre == root->right)))
            {
                res.push_back(root->val);
                pre = root;
                s.pop();
            }
            else
            {
                if (root->right)
                {
                    s.push(root->right);
                }
                if (root->left)
                {
                    s.push(root->left);
                }
            }
        }
        return res;
    }
};