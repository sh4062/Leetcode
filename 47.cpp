class Solution
{
  private:
    vector<vector<int>> res;
    bool canSwap(vector<int> &nums, int begin, int end)
    {
        for (int i = begin; i < end; i++)
        {
            if (nums[i] == nums[end])
                return false;
        }
        return true;
    }

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
                if (canSwap(nums, s, i))
                { //// if previsous loop hasn't this permutation that start with nums[s]
                 ////如果交换中两个数的中间有一个数和后面的交换数相同（说明前面的循环中已经生成过此种排列），则停止生成此种排列。
                    swap(nums[s], nums[i]);
                    permute1(nums, s + 1);
                    swap(nums[s], nums[i]);
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        permute1(nums, 0);
        return res;
    }
};