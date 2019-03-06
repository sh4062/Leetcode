class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> value(row + 1, vector<int>(col + 1, numeric_limits<int>::max()));
        value[row][col-1] = 0;
        for (int i = row - 1; i >= 0; i--)
            for (int j = col - 1; j >= 0; j--)
                value[i][j] =  min(value[i+1][j], value[i][j+1]) + grid[i][j];
        return value[0][0];
        
    }
};