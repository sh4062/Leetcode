class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int sz = max(query_row,query_glass);
        vector<vector<double>> dp(sz+1,vector<double>(sz+1,0));
        dp[0][0]=poured;
        for(int i = 0;i<sz;i++){
            for(int j = 0;j<=i;j++){
                if(dp[i][j]>1){
                    dp[i+1][j]+=0.5*(dp[i][j]-1);
                    dp[i+1][j+1]+=0.5*(dp[i][j]-1);
                }

            }
        }
        return dp[query_row][query_glass]>1?1:dp[query_row][query_glass];

    }
};
