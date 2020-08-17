class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sums=0;
        for_each(nums.begin(),nums.end(),[&sums](int a){sums+=a;});
        if(sums%2!=0)return false;
        int half_sums=sums/2;
        //cout<<half_sums;
        vector<vector<int>>dp(nums.size()+1,vector<int>(half_sums+1,0));
        for(int i = 1;i<=nums.size();i++){
            for(int w = 1;w<=half_sums;w++){
                if(w-nums[i-1]<0)dp[i][w]=dp[i-1][w] ; //zhuang bu xia
                
                else{
                    dp[i][w]=max(dp[i-1][w-nums[i-1]]+nums[i-1],dp[i-1][w]);
                }
                if(dp[i][w]==half_sums)return true;
            }
        }
        
        
        
        return false;
    }
};
