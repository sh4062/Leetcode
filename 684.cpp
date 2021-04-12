class Solution {
public:
    vector<int>parent;
    void Union(int a,int b){
        parent[find(parent[a])]=find(parent[b]);
    }
    int find(int a){
        if(parent[a]!=a){
            parent[a]=find(parent[a]);

        }
        return parent[a];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int l = edges.size();
        parent.resize(l+1);
        for(int i = 0;i<l+1;i++){
            parent[i]=i;
        }
        for(auto edge:edges){
            int n1=edge[0];
            int n2=edge[1];
            if(find(n1)!=find(n2)){
                Union(n1,n2);
            }else{
                return edge;
            }
            
        }
        return vector<int>{};

    }
};
