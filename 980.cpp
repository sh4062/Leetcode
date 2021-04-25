class Solution {
public:
    vector<vector<int>>g;
    int cnt = 0;
    int sum = 0;
    int ret = 0;int sx,sy;
    int ex,ey;
    void dfs(int x,int y,int c){
        //cout<<x<<" "<<y<<endl;
        if(x==ex&&y==ey&&c==sum-cnt-1){
            ret++;
        }
        int res = 0;
        if(x+1<g.size()&&g[x+1][y]!=-1){
            int tmp = g[x+1][y];
            g[x+1][y]=-1;
            dfs(x+1,y,c+1);
            g[x+1][y]=tmp;
        }
        if(x-1<g.size()&&g[x-1][y]!=-1){
            int tmp = g[x-1][y];
            g[x-1][y]=-1;
            dfs(x-1,y,c+1);
            g[x-1][y]=tmp;
        }
        if(y+1<g[0].size()&&g[x][y+1]!=-1){
            int tmp = g[x][y+1];
            g[x][y+1]=-1;
            dfs(x,y+1,c+1);g[x][y+1]=tmp;
        }
        if(y-1>=0&&g[x][y-1]!=-1){
             int tmp = g[x][y-1];
            g[x][y-1]=-1;
            dfs(x,y-1,c+1);
            g[x][y-1]=tmp;
        }

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        g=grid;
        sum = grid.size()*grid[0].size();
        
        
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==-1)
                cnt++;
                if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
                if(grid[i][j]==2){
                    ex=i;
                    ey=j;
                }
            }
        }
        g[sx][sy]=-1;
        g[ex][ey]=1;
        dfs(sx,sy,0);
        return ret;

    }
};
