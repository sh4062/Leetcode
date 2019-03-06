#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int myAtoi(string str)
    {
        int i = 0;
        int j = 0;
        int f = 1;
        int64_t res = 0;
        for (i; i < str.size(); i++)
        {
            if (str[i] == ' ')
            {
                continue;
            }
            if (str[i] == '-')
            {
                f = -1;
                continue;
            }
            if (str[i] == '+')
            {
                f = 1;
                continue;
            }

            if (str[i] >= '0' && str[i] <= '9')
            {
                res = res * 10;
                j++;
                res += (str[i] - '0');

                if (res > INT_MAX)
                {
                    return (INT_MAX + 1) * f;
                }
            }
            else
                break;
        }
        return res * f;
    }
};