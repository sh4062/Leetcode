class Solution {
public:
    int m,n;
    vector<vector<int>> g;
    int dfs(int x,int y){
        //cout<<x<<":"<<y<<":"<<a<<endl;
        int res = 1;
        if(x+1<m&&g[x+1][y]==1){
            g[x+1][y]=0;
            res+=dfs(x+1,y);
        }
        if(y+1<n&&g[x][y+1]==1){
            g[x][y+1]=0;
            res+=dfs(x,y+1);
        }
        if(x-1>=0&&g[x-1][y]==1){
            g[x-1][y]=0;
            res+=dfs(x-1,y);
        }
        if(y-1>=0&&g[x][y-1]==1){
            g[x][y-1]=0;
            res+=dfs(x,y-1);
        }
        return res;


    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        if(m==1&&n==1)return grid[0][0];
        g=grid;
        int ret = 0;
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    g[i][j]=0;
                    ret=max(dfs(i,j),ret);
                }
            }
        }
        return ret;

    }
};
