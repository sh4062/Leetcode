class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 =s1.size();
        int n2 = s2.size();
        if(n1+n2!=s3.size())return false;
        if(s3.size()==0)return true;
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        dp[0][0]=1;
        for(int i = 0;i<n1;i++){
            if(s1[i]==s3[i]){
                dp[i+1][0]=1;
            }else break;
        }
        for(int i = 0;i<n2;i++){
            if(s2[i]==s3[i]){
                dp[0][i+1]=1;
            }else break;
        }
        
        for(int i = 1;i<=n1;i++){
            for(int j = 1;j<=n2;j++){
               if(s1[i-1]==s3[i+j-1])
               dp[i][j]=max(dp[i][j],dp[i-1][j]);
               if(s2[j-1]==s3[i+j-1])
               dp[i][j]=max(dp[i][j],dp[i][j-1]);
               

            }
        }
        


        return dp[n1][n2];

    }
};
