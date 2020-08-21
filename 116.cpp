/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)return root;
        vector<Node*>v;
        vector<Node*>child;
        v.push_back(root);
        while(!v.empty()){
             if(v[0]->left){
                    child.push_back(v[0]->left);
                    
                }
                if(v[0]->right){
                    child.push_back(v[0]->right);
                }
            for(int i =1;i<v.size();i++){
                v[i-1]->next=v[i];
                if(v[i]->left){
                    child.push_back(v[i]->left);
                    
                }
                if(v[i]->right){
                    child.push_back(v[i]->right);
                }
            }
            v=child;
            child.clear();
        }
        return root;
        
    }
};
