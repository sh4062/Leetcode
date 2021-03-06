class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //n天 2次 有没有股票0/1
        int dp[n][2][2];
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=-prices[0];
        dp[0][1][0]=-prices[0];
        //dp[0][2][0]=-prices[0];
        for(int i = 1;i<n;i++){
            for(int j : {0,1}){
                for(int k : {0,1}){
                    //cout<<k;
                    if(k==0){
                        if(j>=1)
                    dp[i][j][k]=max(dp[i-1][j][0],dp[i-1][j-1][1]-prices[i]);
                    else dp[i][j][k]=max(dp[i-1][j][0],-prices[i]);
                    }else{
                   
                    dp[i][j][k]=max(dp[i-1][j][1],dp[i-1][j][0]+prices[i]);
                    
                    }

                }
            }
        }



        return dp[n-1][1][1];




    }
};
