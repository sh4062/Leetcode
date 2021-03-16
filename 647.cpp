class Solution {
public:
    int countSubstrings(string s) {
        // 动态规划法 dp[i][j] 表示字符串s在[i,j]区间的子串是否是一个回文串。
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = 1;
                    ans++;
                }
            }
        }

        return ans;

    }
};
