class Solution
{
  public:
    int maximalSquare(vector<vector<char>> &matrix)
    {

        int row = matrix.size();
        if (row == 0)
            return 0;
        int col = matrix[0].size();
        int res = 0;
        vector<vector<int>> value(row + 1, vector<int>(col + 1, 0));
        value[row][col - 1] = 0;
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    value[i][j] = min(value[i - 1][j], min(value[i][j - 1], value[i - 1][j - 1])) + 1;
                    res = max(value[i][j], res);
                }
            }
        }
        return res * res;
    }
};