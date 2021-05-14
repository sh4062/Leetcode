class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
       
        int ans = 0; 
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
                //if(matrix[i-1][j-1]==1)ans++;
            }
        }
  
        for (int k = 2; k <= min(m,n); ++k) { // 边长
            for (int i = 0; i < m; ++i) { // 坐标，行
                for (int j = 0; j < n; ++j) { // 坐标，列
                        if (i + k > m || j + k  > n) continue;
                        int sum = dp[i + k][j + k] - dp[i][j + k] - dp[i + k][j] + dp[i][j];
                        if (sum <=threshold) ans=max(ans,k);
                }
            }
        }
        return ans;


    }
};
