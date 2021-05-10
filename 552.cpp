#define MOD_CONST 1000000007
class Solution {
public:
    int dfs_vec_memo_order_optim(int n, vector<vector<vector<int>>>& memo, int numA, int numL) {
        if (numA == 2 || numL == 3)
            return 0;
        if (memo[numA][numL][n]  != -1)
            return memo[numA][numL][n];
        if (n == 0)
            return 1;
        return memo[numA][numL][n] = ((dfs_vec_memo_order_optim(n-1, memo, numA, 0) +                 // 'P'
                                       dfs_vec_memo_order_optim(n-1, memo, numA+1, 0)) % MOD_CONST +  // 'A'
                                      dfs_vec_memo_order_optim(n-1, memo, numA, numL+1)) % MOD_CONST; // 'L'
    }
   int checkRecord(int n) {
        if (n == 0 || n == 1)
            return n == 0 ? 1 : 3;
        //vector<unordered_map<string, int>> memo(n+1);
        vector<vector<vector<int>>> memo(2, vector<vector<int>>(3, vector<int>(n+1, -1)));
        //vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(3, vector<int>(2, -1)));
        return dfs_vec_memo_order_optim(n, memo, 0, 0);
    }
};
