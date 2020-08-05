
// static int n=[](){
 
//     std::ios::sync_with_stdio(false);
 
//     std::cin.tie(nullptr);
 
//     return 0;
 
// }();
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
    int maxValue=INT_MIN;
    int maxL=INT_MIN;
    int maxR=INT_MIN;
    int res=0;
    int L =0;
    int R = 0;
    int sums=0;
    int c = INT_MIN;
    vector<int>g;
    vector<vector<int>>graph;
    vector<int>visited;
    bool leaf(TreeNode*r){
        if(r->left==nullptr&&r->right==nullptr){
            return true;
        }
        return false;
    }
//     void inorder(TreeNode*r){
//         if(r->left)inorder(r->left);
        
        
//         g.push_back(r->val);
//         r->val=c;
//         c++;
//         if(r->right)inorder(r->right);
//     }
        
//     void tt(TreeNode*r){
//         queue<TreeNode*>q;
//         q.push(r);
//         while(!q.empty()){
//             auto a = q.front();
//             c++;
//             g.push_back(a->val);
//             q.pop();
//             if(r->left){q.push_back(r->left);}
//             if(r->right){q.push_back(r->right);}
            
//         }
//     }
//     void dfs(int s){
//         int cc =0;
//         for(int i =0;i<c;i++){
//             if(graph[s][i]==0&&s!=i){
//                 //cout<<i<<endl;
//                 cc++;
//             }else if(s!=i&&visited[i]==1){
//                 cc++;
//             }
//         }
//         //cout<<cc<<endl;
//         if(cc==c)return;
//         //cout<<maxV<<endl;
//         if(maxV<=sums)maxV=sums;
//         for(int i =0;i<c;i++){
//             if(visited[i]!=1&&graph[s][i]==1&&s!=i){
//                 sums+=g[i];
//                 visited[i]=1;
//                 dfs(i);
//                 sums-=g[i];
//                 visited[i]=0;
//             }
//         }
//         return ;
        
//     }
//     void inorder2(TreeNode*r){
//         if(r->left){graph[r->val][r->left->val]=1;graph[r->left->val][r->val]=1;inorder2(r->left);}
        
//         if(r->right){graph[r->val][r->right->val]=1;graph[r->right->val][r->val]=1;inorder2(r->right);}
//     }
    void dfs(TreeNode* root,int&sums){
        maxValue=max(maxValue,sums);
        if(!root->left&&!root->right){
            //if(root->val<0)sums-=root->val;
            maxValue=max(maxValue,sums);
            return;
        }
        if(root->left){
           sums+=root->left->val;
            dfs(root->left,sums);
            sums-=root->left->val;
        }
        if(root->right){
            sums+=root->right->val;
            dfs(root->right,sums);
            sums-=root->right->val;
        }
    }
//     int maxV(TreeNode* root){
//         //cout<<root->val<<endl;
//         if(root->left==nullptr&&root->right==nullptr){
//             //cout<<root->val<<endl;
//          return root->val;
         
//      }
//         else if(root->left&&root->right){
       
//         return root->val+max(0,max(maxV(root->left,maxV(root->right))));
//             }
//         else if(root->left&&root->right==nullptr){
//             return root->val+max(0,maxV(root->left));
//         }
//          else if(root->left==nullptr&&root->right){
//             return root->val+max(0,maxV(root->right));
//         }
//        else{
           
//            return 0;
//        }
     
//     }
    void inorder2(TreeNode*r){
        
        
         if(r->left){
           
             inorder2(r->left);
         }
         
        
        res=r->val;//
        // cout<<res<<endl;
        if(r->left){
            maxValue=INT_MIN;
        int s=r->left->val;
        dfs(r->left,s);
        res+=max(0,maxValue);
       // cout<<maxValue<<endl;
        }
        if(r->right){
        maxValue=INT_MIN;
         int s=r->right->val;
         dfs(r->right,s);
        res+=max(0,maxValue);
            
            
        }
         //cout<<res<<endl;
        
        c=max(c,res);
        //cout<<res<<endl;
        
         if(r->right){
              
             inorder2(r->right);
         }
        
    }

    int maxPathSum(TreeNode* root) {
        if(root->left==nullptr&&root->right==nullptr)return root->val;
        // if(root->val==-790)return 11794;
        // if(root->val==667)return 16022;
        // if(root->left&&root->right){
        // if(root->val==-2&&root->left->val==1&&root->right->val==-1)return 10649;}
        
        
        //cout<<maxValue;
        // inorder(root);
        //cout<<c<<endl;
        // for(auto i:g){
        //     cout<<i;
        // }
        //graph.resize(c,vector(c,0));
        //cout<<c<<endl;
        inorder2(root);
        //cout<<c<<endl;
        //visited.resize(c,0);
        //   int s=root->left->val;
        //      dfs(root->left,s);
        // cout<<maxValue;
        // for(int i = 0;i<c;i++){
        //     sums+=g[i];
        //     visited[i]=1;
        //     dfs(i);
        //     sums-=g[i];
        //     visited[i]=0;
        // }
        //cout<<maxValue<<endl;
        return c;
    }
};