class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>que;
        if(grid[0][0]==1)return -1;
        int n = grid.size();
        que.push({0,0});
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        int res = 1;
        while(!que.empty()){
            int s = que.size();
            for(int i = 0;i<s;i++){
                auto q = que.front();que.pop();
                if(q.first==n-1&&q.second==n-1)return res;
                if(q.first+1<n&&grid[q.first+1][q.second]==0){
                    grid[q.first+1][q.second]=1;
                    que.push({q.first+1,q.second});

                }
                if(q.first-1>=0&&grid[q.first-1][q.second]==0){
                    grid[q.first-1][q.second]=1;
                    que.push({q.first-1,q.second});

                }
                if(q.second+1<n&&grid[q.first][q.second+1]==0){
                    grid[q.first][q.second+1]=1;
                    que.push({q.first,q.second+1});

                }
                if(q.second-1>=0&&grid[q.first][q.second-1]==0){
                    grid[q.first][q.second-1]=1;
                    que.push({q.first,q.second-1});

                }
                if(q.first+1<n&&q.second+1<n&&grid[q.first+1][q.second+1]==0){
                    grid[q.first+1][q.second+1]=1;
                    que.push({q.first+1,q.second+1});

                }
                if(q.first+1<n&&q.second-1>=0&&grid[q.first+1][q.second-1]==0){
                    grid[q.first+1][q.second-1]=1;
                    que.push({q.first+1,q.second-1});

                }
                if(q.second+1<n&&q.first-1>=0&&grid[q.first-1][q.second+1]==0){
                    grid[q.first-1][q.second+1]=1;
                    que.push({q.first-1,q.second+1});

                }
                if(q.first-1>=0&&q.second-1>=0&&grid[q.first-1][q.second-1]==0){
                    grid[q.first-1][q.second-1]=1;
                    que.push({q.first-1,q.second-1});

                }
            }
            res++;

        }
        return -1;

    }
};
