class Solution {
public:
    vector<vector<int>>m;
    int n;
    int res = INT_MAX;
    vector<vector<int>>dp;
    int dfs(int x,int y,int c){
       
        if(x==n-1){
            res = min(res,c);
            return c;
        }
        if(y-1>=0){
            dfs(x+1,y-1,c+m[x+1][y-1]);
        }
        if(y+1<n){
            dfs(x+1,y+1,c+m[x+1][y+1]);
        }
        dfs(x+1,y,c+m[x+1][y]);
        return c; 

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        dp.resize(n,vector<int>(n,0));
        m = matrix;
        // for(int i = 0;i<n;i++){
        //     dfs(0,i,m[0][i]);
        // }
        for(int i = 0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
                if(j==0)dp[i][j] = min(dp[i-1][j]+matrix[i][j],dp[i-1][j+1]+matrix[i][j]);
                else if(j==n-1)dp[i][j] = min(dp[i-1][j]+matrix[i][j],dp[i-1][j-1]+matrix[i][j]);
                else
                dp[i][j] = min(dp[i-1][j]+matrix[i][j],min(dp[i-1][j-1]+matrix[i][j],dp[i-1][j+1]+matrix[i][j]));
            }
        }
        for(int i = 0;i<n;i++){
            res=min(res,dp[n-1][i]);
        }
        return res;

    }
};
