#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    Solution()
    {
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;
    }
    int romanToInt(string s)
    {
        int n = s.size();
        int res = 0;
        int i = 0;
        while (i < n)
        {
            if (i < n - 1 && dict[s[i]] < dict[s[i + 1]])//"IV"为4 若出现左面小于右面则减去左边 否则加上就行 Ex:"MCMXCIV" 1994 1000-100+1000-10+100-1+5
            {
                res -= dict[s[i]];
                res += dict[s[i + 1]];
                i += 2;
            }
            else
            {
                res += dict[s[i]];
                i += 1;
            }
        }
        return res;
    }
    ~Solution()
    {
        dict.clear();
    }

  private:
    unordered_map<char, int> dict;
};