class Solution
{
  public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res0;
        vector<int> tmp;
        if (n == 0)
            return res0;
        if (n == 1)
        {
            tmp.push_back(1);
            res0.push_back(tmp);
            return res0;
        }
        vector<vector<int>> res(n, vector<int>(n, 0));
        int row = 0;
        int col = 0;
        int cur = 0;
        int n1 = n, n2 = n;
        int cnt = 1;
        while (row < n1 && col < n2)
        {
            for (cur = row; cur < n1; cur++)
            {
                res[col][cur] = (cnt++);
                if (res.size() == n * n)
                    return res;
            }
            col++;
            for (cur = col; cur < n2; cur++)
            {
                res[cur][n1 - 1] = (cnt++);
                if (res.size() == n * n)
                    return res;
            }
            n1--;
            for (cur = n1 - 1; cur >= row; cur--)
            {
                res[n2 - 1][cur] = (cnt++);
                if (res.size() == n * n)
                    return res;
            }
            n2--;
            for (cur = n2 - 1; cur >= col; cur--)
            {
                res[cur][row] = (cnt++);
                if (res.size() == n * n)
                    return res;
            }
            row++;
        }
        return res;
    }
};