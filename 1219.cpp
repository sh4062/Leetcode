class Solution {
public:
    vector<vector<int>> g;
    int m;
    int n;
    int res;
    void dfs(int x,int y,int c){
        //cout<<x<<" "<<y<<endl;
        
        c+=g[x][y];
        res=max(res,c);
        int tmp = g[x][y];
        g[x][y] = 0;
        if(x+1<m&&g[x+1][y]!=0){
            
            dfs(x+1,y,c);
        }
        if(x-1>=0&&g[x-1][y]!=0){
            dfs(x-1,y,c);
        }
        if(y+1<n&&g[x][y+1]!=0){
            dfs(x,y+1,c);
        }
        if(y-1>=0&&g[x][y-1]!=0){
            dfs(x,y-1,c);
        }
        g[x][y] = tmp;
        

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        g=grid;
        res = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]!=0)
                dfs(i,j,0);
            }
        }
        return res;


    }
};
