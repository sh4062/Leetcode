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
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> res;
        if(root==nullptr) return res;
        res.resize(1);
        queue<Node*>q;
        q.push(root);
        q.push(nullptr);
        int l = 0;
        int qs = 5;
        int tmp;
        while(q.size()!=1){
            
            
            
            if(q.front()==nullptr){
                
                l++;
                res.resize(l+1);
                q.pop();
                q.push(nullptr);
                
            }else{
                res[l].push_back(q.front()->val);
                
                
            for(int i = 0;i<q.front()->children.size();i++){
                q.push(q.front()->children[i]);
                
            }q.pop();}
            
            
            
           
        }
    return res;
    }
};