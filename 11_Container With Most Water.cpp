#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int maxA = (j - i) * (min(height[i], height[j]));
        while (i < j)
        {
            maxA = max(maxA, (j - i) * (min(height[i], height[j])));
            if (height[i] <= height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxA;
    }
};