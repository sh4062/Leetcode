class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        for(int j = 0;j<=n;j++)dp[0][j]=0;
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                // if(j>1&&j<n)
                // dp[i][j]=min(dp[i-1][j-1]+arr[i-1][j-1],dp[i-1][j+1]+arr[i-1][j-1]);
                // else if(j==1){
                //     dp[i][j]=dp[i-1][j+1]+arr[i-1][j-1];
                // }
                // else if(j==n){
                //     dp[i][j]=dp[i-1][j-1]+arr[i-1][j-1];
                // }
                for(int k = 1;k<=m;k++){
                    if(k==j)continue;
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+arr[i-1][k-1]);
                }
            }
        }
        int res = INT_MAX;
        for(int i = 1;i<=n;i++){
            //cout<<dp[1][i]<<endl;
            res=min(res,dp[m][i]);
        }
        return res;
    }
};
