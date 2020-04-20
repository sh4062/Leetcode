/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int d(Node* root,int&a){
        if(root==nullptr||root->children.size()==0) return a;
        
        vector<int> dd;
        int dc = 1;
        for(int i = 0;i<root->children.size();i++){
            
            
            dd.push_back(d(root->children[i],dc));}
       return 1+*max_element(dd.begin(),dd.end());
    }
    int maxDepth(Node* root) {
        if(root==nullptr) return 0;
        int a = 1;
        int  res = d(root,a);
        return res;}
};