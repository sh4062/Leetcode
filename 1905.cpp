class Solution {
public:
vector<vector<int>>g1;
    int res = 0;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int dfs(int x,int y,vector<vector<int>>& g){
        int ret = 0;
        if(g1[x][y]==0){
                    ret+=1;
                }
        for(int k =0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx>=0&&xx<g.size()&&yy>=0&&yy<g[0].size()&&g[xx][yy]==1){
                g[xx][yy]=0;
                if(g1[xx][yy]==0){
                    ret+=1;
                }
                ret+=dfs(xx,yy,g);
            }

        }
        return ret;


    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        g1=grid1;
        for(int i = 0;i<grid1.size();i++){
            for(int j = 0;j<grid1[0].size();j++){
                if(grid2[i][j]==1){
                    int r = dfs(i,j,grid2);
                    //cout<<r<<endl;
                    if(r==0)res++;
                }
            }
        }
        return res;

    }
};
