class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        if(grid.size()==0)return res;
        for(int i = grid.size()-1;i>=0;i--){
            for(int j = grid[0].size()-1;j>=0;j--){
                if(grid[i][grid[0].size()-1]>0){
                    j=-1;
                    continue;
                }
                else if(grid[i][0]<0){
                    res+=(grid[0].size());
                    j=-1;
                    continue;
                    
                }else{
                    if(grid[i][j]<0){
                        res++;
                    }
                }
        }
        }
        return res;
    }
};