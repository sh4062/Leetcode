class Solution {
public:
    vector<int> visited;
    vector<int> path;
    vector<vector<int>> G;
    vector<vector<int>> res;
    int c ;
    void dfs(int s, int t,vector<int> &visited,vector<int>&path){
        
        //cout<<t;
        if(t==c-1){
            
           // path.push_back(c-1);
            res.push_back(path);
        }
         for (int k = 0; k < c; ++k){
            if(G[t][k]==1&&visited[k]==0){
            path.push_back(k);
            visited[k]=1;
            dfs(t,k,visited,path);
            path.pop_back();
             visited[k]=0;}
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        c = graph.size();
        visited.resize(c);//r行
        G.resize(c);
        for (int k = 0; k < c; ++k){
            //visited[k].resize(c);//每行为c列
            G[k].resize(c);
            visited[k] = 0;
        }
        for(int i = 0;i<c;i++){
            for(int j = 0;j < c;j++){
                //visited[i][j] = 0;
                G[i][j] = 0;
                
            }
        }
        for(int i = 0;i<graph.size();i++){
            for(int j = 0;j < graph[i].size();j++){
                G[i][graph[i][j]] = 1;
                //G[i][j]
                
            }
        }
        path.push_back(0);
        visited[0] = 1;
        for (int k = 0; k < c; ++k){
            if(G[0][k]==1){
                 path.push_back(k);
            visited[k]=1;
            dfs(0,k,visited,path);
                 path.pop_back();
             visited[k]=0;
            }
        }
        //visited[1] = 1;
        //dfs(0,2,visited,path);
        return res;
    }
};