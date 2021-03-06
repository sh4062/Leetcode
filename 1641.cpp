class Solution {
public:
    int countVowelStrings(int n) {
        if(n==0)return 0;
        vector<int>dp={1,1,1,1,1};
        for(int i = 1;i<n;i++){
            dp[0] = dp[0]+dp[1]+dp[2]+dp[3]+dp[4];
            dp[1] =dp[1]+dp[2]+dp[3]+dp[4];
            dp[2]=dp[2]+dp[3]+dp[4];
            dp[3]=dp[3]+dp[4];
            dp[4]=dp[4];
            
        }
        return accumulate(dp.begin(),dp.end(),0);

    }
};
