class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        // 前缀和数组
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            // 数组非递减，则left >= 0 且 riht >= 0
            int left = nums[i] * i - (sum[i] - sum[0]);
            int right = sum[n] - sum[i + 1] - nums[i] * (n - i - 1);
            res[i] = left + right;
        }
        return res;

    }
};
