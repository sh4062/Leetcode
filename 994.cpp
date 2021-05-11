class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        queue<int>q;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==2){
                    q.push(i*n+j);
                    grid[i][j]=0;
                }
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        if(cnt==0)return 0;

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int res = 0;
        while(!q.empty()){
            //cout<<q.size()<<endl;
            for(int i = q.size();i>0;i--){
                auto tmp = q.front();
                q.pop();
                int x = tmp/n;
                int y =tmp%n;
                for(int k = 0;k<4;k++){
                    int xx=x+dx[k];
                    int yy =y+dy[k];
                    if(xx>=0&&xx<m&&yy>=0&&yy<n&&grid[xx][yy]==1){
                        grid[xx][yy]=0;
                        q.push(xx*n+yy);
                        cnt--;
                    }
                    

                }


            }
            res++;
        }
        return cnt==0?res-1:-1;

    }
};
