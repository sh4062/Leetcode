class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector om(m,0);
        vector on(n,0);
        for(int i = 0;i<m;i++){
            om[i] = *max_element(grid[i].begin(),grid[i].end());
        }
        for(int i = 0;i<n;i++){
            int tmp = 0;
            for(int j = 0;j<m;j++){
                tmp=max(tmp,grid[j][i]);
            }
            on[i]=tmp;
        }
        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int minn = min(om[i],on[j]);
                if(grid[i][j]<minn){
                    cnt+=minn-grid[i][j];
                }
            }
        }
        return cnt;

    }
};
