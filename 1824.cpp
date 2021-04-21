class Solution {
public:
    int minSideJumps(vector<int>& ob) {
        int n = ob.size();
        vector<vector<int>> dp(n, vector<int>(3, n+1) );
        dp[0][1] = 0;
        dp[0][0] = 1;
        dp[0][2] = 1;

        for(int i=1; i<n; ++i)
        {
            if(ob[i] != 1) dp[i][0] = dp[i-1][0];
            if(ob[i] != 2) dp[i][1] = dp[i-1][1];
            if(ob[i] != 3) dp[i][2] = dp[i-1][2];
            if(ob[i] != 1) dp[i][0] = min(dp[i][0], min(dp[i][1], dp[i][2]) + 1);
            if(ob[i] != 2) dp[i][1] = min(dp[i][1], min(dp[i][0], dp[i][2]) + 1);
            if(ob[i] != 3) dp[i][2] = min(dp[i][2], min(dp[i][0], dp[i][1]) + 1);
            
        }
        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));

    }
};
