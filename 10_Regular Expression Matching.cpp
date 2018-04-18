// borrowed from https://github.com/zhuli19901106/leetcode-2/blob/master/regular-expression-matching_1_AC.cpp#L46
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        stack<char> sc;
        stack<int> si;
        stack<int> sj;
        int ls = s.size();
        int lp = p.size();
        int i, j, k;
        i = 0;
        j = 0;
        while (i < ls || j < lp)
        {
            if (j + 1 < lp && p[j + 1] == '*')
            {
                // Star match
                sc.push(p[j]);
                si.push(i);
                j += 2;
                sj.push(j);
            }
            else if (j < lp && (p[j] == '.' || s[i] == p[j]))
            {
                // Single match
                ++i;
                ++j;
            }
            else if (!sc.empty())
            {
                // Turn back and try again
                k = si.top();
                if (k < ls && (sc.top() == '.' || sc.top() == s[k]))
                {
                    ++k;
                    i = si.top() = k;
                    j = sj.top();
                }
                else
                {
                    sc.pop();
                    si.pop();
                    sj.pop();
                }
            }
            else
            {
                // Mismatch and no turning back.
                // Or full match
                break;
            }
        }
        bool res = (i == ls && j == lp);

        // while (!sc.empty())
        // {
        //     sc.pop();
        //     si.pop();
        //     sj.pop();
        // }

        return res;
    }
};
// This problem has a typical solution using Dynamic Programming. We define the state P[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. Then the state equations are:

// P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
// P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
// P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.
// Putting these together, we will have the following code.

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length(); 
        vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        return dp[m][n];
    }
};