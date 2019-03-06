class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int cmin = INT_MAX;
        int sum;
        for (int i = 0; i < nums.size(); i++)
        {
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back)
            {
                sum = nums[i] + nums[front] + nums[back];
                cmin = (abs(cmin) < abs(sum - target)) ? cmin : sum - target;
                //r=target+cmin;
                if (sum < target)
                {
                    front++;
                }
                else if (sum > target)
                {
                    back--;
                }
                else
                {
                    return target;
                }
            }
        }
        return target + cmin;
    }
};