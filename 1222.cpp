class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
 vector<vector<int>> grid(8, vector<int>(8, 0));
        vector<vector<int>> res;
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1,  0,  1, 1, 1, 0,-1,-1};
        for(int i = 0; i < queens.size(); ++i)
        {
            grid[queens[i][0]][queens[i][1]] = 1;
        }
        for(int i = 0; i < 8; ++i)
        {
            int x = king[0] + dx[i];
            int y = king[1] + dy[i];
            while(x >= 0 && x < 8 && y >=0 && y < 8)
            {
                if(grid[x][y])
                {
                    res.push_back({x, y});
                    break;
                }
                x += dx[i];
                y += dy[i];
            }
        }
        return res;
    }
};
