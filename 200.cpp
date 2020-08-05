class Solution {
public:
    int w;
    int h;
    int xd[4]={-1,1,0,0};
    int yd[4]={0,0,-1,1};
    int res = 0;
    bool valid(int x,int y){
        return x<h&&x>=0&&y>=0&&y<w;
        
    }
    vector<vector<char>> g;
    int bfs(int i,int j,vector<vector<char>>& grid){
        res++;
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]='1';
       
        while(!q.empty()){
             int s = q.size();
            while(s--){
            auto p =q.front();
            q.pop();
            for(int ii = 0;ii<4;ii++){
                
                int xx = p.first+xd[ii];
                int yy = p.second+yd[ii];
                //cout<<xx<<" "<<yy<<endl;
                if(valid(xx,yy)&&g[xx][yy]=='1'&&grid[xx][yy]=='0'){
                    //cout<<xx<<" "<<yy<<endl;
                    grid[xx][yy]='1';
                    q.push({xx,yy});
                }
            }
        }
            
        }
        
        return 0;
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()<1)return 0;
        g=grid;
        h=grid.size();
        w=grid[0].size();
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                }
            }
        }
        
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(g[i][j]=='1'&&grid[i][j]=='0'){
                    bfs(i,j,grid);
                }
            }
        }
//         for(int i = 0;i<grid.size();i++){
//             for(int j = 0;j<grid[0].size();j++){
                 
//                     cout<<grid[i][j];
                
//             }
//             cout<<endl;
//         }
        return res;
        
    }
};
