class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int dp[1000000]={1};
        int res=0;
        for(int i = 0;i<nums.size();i++){
            int tmp = 0;/* 记录满足条件的、第i个数左边的上升子序列的最大长度 */
            for (int j = 0; j <i; ++j) {
            /* 查看以第j个数为终点的最长上升子序列 */
            if (nums[i] >nums[j]) {
                tmp = max(tmp,dp[j]);
            }
        }
        dp[i] = tmp + 1;
        res=max(res,dp[i]);
        }
        return res;
    }
};
