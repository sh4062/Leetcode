class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int res = 0;
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i = 1;i<=s1.size();i++){
            for(int j =1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+int(s1[i-1]);
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int sum=0;
        for(int j = 0; j < s1.size(); ++j)
            sum += int(s1[j]);
        for(int j = 0; j < s2.size(); ++j)
            sum += int(s2[j]);

        return sum-2*dp[s1.size()][s2.size()];

    }
};
