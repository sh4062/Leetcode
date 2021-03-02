class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0)return 0;
        if(prices.size()<=1)return 0;
        int dp[prices.size()][k][2];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<k;i++)
        dp[0][i][0]=-prices[0];
        for(int i = 1;i<prices.size();i++){
            for(int j=0;j<k;j++){
                for(int kk : {0,1}){
                    if(kk==0){
                        if(j>0){
                            dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j-1][1]-prices[i]);
                        }else{
                            dp[i][j][0]=max(dp[i-1][j][0],-prices[i]);
                        }

                    }else{
                        dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j][0]+prices[i]);

                    }

                }
            }
        }
        return dp[prices.size()-1][k-1][1];

    }
};
