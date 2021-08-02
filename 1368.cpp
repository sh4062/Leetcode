class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        q.push({0,0});
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>cost(m,vector<int>(n,INT_MAX-1000));
        cost[0][0]=0;
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            int x = tmp.first;
            int y = tmp.second;
            for(int k=0;k<4;k++){
                int xx = x+dx[k];
                int yy = y+dy[k];
                if(xx<0||xx>=m||yy<0||yy>=n)continue;
                //cout<<xx<<" "<<yy<<endl;
                int cost_grid = grid[x][y]==k+1?0:1;
                int cur = cost[x][y]+cost_grid;
                if(cur<cost[xx][yy]){
                    cost[xx][yy]=cur;
                    q.push({xx,yy});
                }
            }
        }
        return cost[m-1][n-1];

    }
};
