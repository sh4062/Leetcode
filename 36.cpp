class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            unordered_map<char, bool> box;
            unordered_map<char, bool> row;
            unordered_map<char, bool> col;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (row[board[i][j]]==true)
                    {
                        return false;
                    }
                    else
                    {
                        row[board[i][j]] = true;
                    }
                }
                if (board[j][i] != '.')
                {
                    if (col[board[j][i]]==true)
                    {
                        return false;
                    }
                    else
                    {
                        col[board[j][i]] = true;
                    }
                }
                if (board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] != '.')//第i个九宫格的第j个节点
                {
                    if (box[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]]==true)
                    {
                        return false;
                    }
                    else
                    {
                        box[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]]=true;

                    }
                }
            }
        }
        return true;
    }
};