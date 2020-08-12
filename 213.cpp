class Solution {
public:
    int rob(vector<int>& nums) {
         int len=nums.size();
        if(len<1)return 0;
        if(len==1)return nums[0];
        if(len==2)return max(nums[0],nums[1]);
        int res=0;
        //vector<int>dp(len+1,0);
        int dp[101][101]={0};
        
        for(int s= 0;s<len-1;s++){
        dp[s][0]=nums[s];
        dp[s][1]=nums[s];
        }
        for(int s= 0;s<len;s++){
        for(int i = 2;i<len-1;i++){
                dp[s][i]=max(dp[s][(s+i-2-1<0?s+i-2-1+len:i-2)%(len)]+nums[(s+i)%len],dp[s][i-1]);
                //if(s==4)cout<<" "<<s<<" "<<i<<nums[(s+i)%len]<<endl;//dp[s][i]>=3
        }       
        }
        for(int s= 0;s<len;s++){
            res = max(res,dp[s][len-2]);
        }
        //cout<<dp[4][6];
        return res;
        
    }
};
