class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        //vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof dp);
        int res = 0; 
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
                //if(matrix[i-1][j-1]==target)res++;
            }
        }
         for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= i; k++)
                    for (int l = 1; l <= j; l++) {
                        int sum = dp[i][j] - dp[i][l - 1] - dp[k - 1][j] + dp[k - 1][l - 1];
                        if (sum == target)
                            res++;
                    }
        
        return res;


    }
};
