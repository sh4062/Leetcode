class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,1);
        vector<int>count(n+1,1);
        dp[0]=1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                    count[i]=count[j];}
                    
                    else if(dp[j]+1==dp[i]){
                        count[i]+=count[j];
                    }
                }
        }
        }
        
        int len = *max_element(dp.begin(),dp.end());
        //cout<<len;
        if(len==1) return nums.size();
        int res = 0;
        for(int i = 0;i<n;i++){
            if(dp[i]==len){
                res+=count[i];
                //cout<<count[i]<<endl;
            }
        }
        
        return res;

    }
};
