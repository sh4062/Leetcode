class Solution {
public:
    int integerBreak(int n) {
        if(n==1)return 1;
        if(n==2)return 1;
        if(n==3)return 2;
        // vector<int>v;
        // for(int i =1;i<n;i++)v.push_back(i);
        //int res = 0;
        // int dp [100]={0};
        int dp_max [100]={0};
        // dp[1]=1;
        // dp[2]=2;
        dp_max[1]=1;
        dp_max[2]=2;
        dp_max[3]=3;
        for(int i =3;i<=n;i++){
            //cout<<i/2;
            for(int j = 1;j<=i/2;j++){
                if(j!=i-j){
                //dp[i]+=dp[j]*dp[i-j];
                //cout<<j<<" "<<i-j<<" "<<dp_max[j]*dp_max[i-j]<<endl;
                dp_max[i]=max(dp_max[i],max(dp_max[j]*dp_max[i-j],j*(i-j)));}
                else{
                   // dp[i]+=dp[j];
                    dp_max[i]=max(dp_max[i],max(dp_max[j]*dp_max[j],j*j));
                
            }
                                  }
            
        }
        return dp_max[n];
        
        
        
    }
};
