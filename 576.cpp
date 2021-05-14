int mod = int(pow(10,9))+7;
class Solution {
public:
    vector<vector<vector< int>>>memo;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int dfs(int m, int n,int left,int x,int y){
        if(left<=0)return 0;
        if(memo[x][y][left]!=-1)return memo[x][y][left];
        int r =0;
        for(int k = 0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx<0||xx>=m||yy<0||yy>=n){
                r++;
            }else{
                r+=dfs(m,n,left-1,xx,yy);
            }
            r%=mod;
        }
        memo[x][y][left]=r;
        return r;

    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memo.resize(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        int ret = dfs(m,n,maxMove,startRow,startColumn);
        return ret;

    }
};
