class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int res = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=nums2.size();j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    
                }else{
                    dp[i][j] = 0;
                }
                res = max(res,dp[i][j]);
            }
        }
        return res;

    }
};
