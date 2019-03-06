class Solution
{
  private:
    vector<vector<int>> res;

  public:
    void permute1(vector<int> &nums, int s)
    {
        if (s == nums.size())
        {
            res.push_back(nums);
            return;
        }
        else
        {
            for (int i = s; i < nums.size(); i++)
            {
                swap(nums[s], nums[i]);
                permute1(nums, s + 1);
                swap(nums[s], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        permute1(nums, 0);
        return res;
    }
};