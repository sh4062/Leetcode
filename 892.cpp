class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]!=0)
                res+=grid[i][j]*4+2;
                if(i>0)res-=min(grid[i-1][j],grid[i][j])*2;
                if(j>0)res-=min(grid[i][j-1],grid[i][j])*2;
            }
        }
        return res;


    }
};
