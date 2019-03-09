class Solution
{
  public:
    int n; //皇后个数
    int count = 0;
    int x[100];
    bool isvalid(int k, int i)
    {
        for (int j = 0; j < k; j++)
        {
            if ((x[j] == i) || abs(x[j] - i) == abs(j - k))
                return false;
        }
        return true;
    }
    void nQueens(int k, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (isvalid(k, i))
            {
                x[k] = i;
                if (k == n - 1)
                {
                    count++;
                    // for (i = 0; i < n; i++)
                    //     cout << x[i] << " ";
                    // cout << endl;
                }
                else
                    nQueens(k + 1, n);
            }
        }
    }
    int totalNQueens(int n)
    {
        nQueens(0, n);
        return count;
    }
};