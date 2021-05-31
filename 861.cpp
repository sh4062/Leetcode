class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //行
        for(int i = 0;i<m;i++){
            if(grid[i][0]!=1){
                for(int j = 0;j<n;j++){
                    grid[i][j]^=1;
                }
            }
        }
        //列
        for(int j = 1;j<n;j++){
            int cur = 0;
            for(int i = 0;i<m;i++){
            
                if(grid[i][j]==0)cur++;
            
            }
            if(cur>m/2)
            for(int i = 0;i<m;i++){
                grid[i][j]^=1;
            }
        }
        //sum
        int res = 0;
        for(int i = 0;i<m;i++){
            int row = 0;
            int p = 0;
            for(int j = n-1;j>=0;j--){
                    if(grid[i][j])
                    row+=pow(2,p);
                    p++;
            }
            //cout<<row<<endl;
            res+=row;

        }
        return res;


    }
};861
