class Solution {
public:
    int memo[71][71][71];
    int m,n;
    vector<vector<int>>g;
    int dfs(int layer,int l,int r){
        
        if(layer==m){
            return 0;
        }

        if(memo[layer][l][r]!=-1)return memo[layer][l][r];
        int ret = 0;
        for(int i = -1;i<=1;i++){
            for(int j =-1;j<=1;j++){
                if(layer<m&&l+i>=0&&l+i<n&&r+j>=0&&r+j<n&&l+i!=r+j){
                    ret=max(ret,dfs(layer+1,l+i,r+j));
                }
            }
        }
        
        return memo[layer][l][r]=ret+g[layer][l]+g[layer][r];
        

    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(memo,-1,sizeof(memo));
        m = grid.size();
        n = grid[0].size();
        g=grid;
        return dfs(0,0,n-1);

    }
};
