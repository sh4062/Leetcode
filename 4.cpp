#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> tmp;
        int i = 0, j = 0;
        //nums1.push_back(INT_MAX);
        //nums2.push_back(INT_MAX);
        int len = nums1.size() + nums2.size();
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {

                tmp.push_back(nums1[i]);
                i++;
            }
            else
            {

                tmp.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size())
        {
            tmp.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size())
        {
            tmp.push_back(nums2[j]);
            j++;
            //cout<<nums2.size();
        }
        // cout<<tmp.size();
        if (tmp.size() % 2 != 0)
            return tmp[tmp.size() / 2];
        else
        {
            double a = tmp[tmp.size() / 2];
            double b = tmp[tmp.size() / 2 - 1];
            //cout<<b;
            return (a + b) / 2;
        }
    }
};