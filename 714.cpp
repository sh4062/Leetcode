class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
           if(prices.size()==0)return 0;
         int n = prices.size();
        //n天 有没有股票0/1
        int dp[n][2];
        memset(dp,0,sizeof(dp));
        dp[0][0]=-prices[0];
        //dp[0][2][0]=-prices[0];
        for(int i = 1;i<n;i++){
                for(int k : {0,1}){
                    //cout<<k;
                    if(k==0){
                    if(i>=1)
                    dp[i][k]=max(dp[i-1][0],dp[i-1][1]-prices[i]);
                    else{
                        dp[i][k]=max(dp[i-1][0],-prices[i]);
                    }
                    }else{
                   
                    dp[i][k]=max(dp[i-1][1],dp[i-1][0]+prices[i]-fee);
                    
                    }

                }
            }
        



        return dp[n-1][1];
        

    }
};
