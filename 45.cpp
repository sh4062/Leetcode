class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // int dp[n];


        // for(int i = 0;i<n;i++){
        //     dp[i] = n;
        // }
        // dp[0]=0;
        // // for(auto i:dp){
        // //     cout<<i<<endl;
        // // }
        // for(int i = 1;i<n;i++){
        //     for(int j = 0;j<=i;j++){
        //         if(j+nums[j]>=i&&dp[i]>dp[j]+1){
        //             dp[i]=dp[j]+1;

        //         }
        //     }
        // }
        // // for(auto i:dp){
        // //     cout<<i<<endl;
        // // }
        // return dp[n-1];
        int right = 0;
        int preright = 0;
        int step = 0;
        for(int i = 0;i<n-1;i++){
            //if(i<=right){
                right = max(right,i+nums[i]);
                if(i == preright){
                    step++;
                    preright = right;
                }
            //}
        }
        return step;

    }
};
