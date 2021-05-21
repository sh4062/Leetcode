class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<int>q;
        unordered_set<int>vis;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i<m;i++){
            if(grid[i][0]==1){
                q.push(i*n);
                vis.insert(i*n);
            }
            if(grid[i][n-1]==1){
                q.push(i*n+n-1);
                vis.insert(i*n+n-1);
            }
        }
        for(int i = 0;i<n;i++){
            if(grid[0][i]==1){
                q.push(i);
                vis.insert(i);
            }
            if(grid[m-1][i]==1){
                q.push((m-1)*n+i);
                vis.insert((m-1)*n+i);
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            auto tmp = q.front();
            int x =tmp/n;
            int y=tmp%n;
            q.pop();
            
            for(int k = 0;k<4;k++){
                int xx=x+dx[k];
                int yy=y+dy[k];
                if(xx>=0&&xx<m&&yy>=0&&yy<n&&!vis.count(xx*n+yy)&&grid[xx][yy]==1){
                   q.push(xx*n+yy);
                   vis.insert(xx*n+yy);
                }
            }

        }
        int res = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    res++;
                }

            }
        }
        // cout<<;
        return res-vis.size();

    }
};
