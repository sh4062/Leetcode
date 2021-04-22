class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
if (A.empty()) {
            return 0;
        }

        int N = A.size();
        vector<vector<int>> dp(N, vector<int>(20010, 1));

        int res = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                auto diff = A[i] - A[j];
                int offset = 10000;
                diff += offset;
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                res = max(dp[i][diff], res);
            }
        }

        return res;


    }
};
