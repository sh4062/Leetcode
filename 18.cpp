class Solution
{
  public:
    void nSum(vector<int> nums, int n, int target, vector<int> &cur_res, vector<vector<int>> &results)
    {
        int len = nums.size();
        if (len < n || n < 2 || target < nums[0] * n || target > nums[len - 1] * n)
            return;

        if (n == 2)
        {
            int l = 0;
            int r = len - 1;

            while (l < r)
            {
                int sum = nums[l] + nums[r];

                if (sum < target)
                    l++;
                else if (sum > target)
                    r--;
                else
                {
                    cur_res.push_back(nums[l]);
                    cur_res.push_back(nums[r]);
                    results.push_back(cur_res);
                    cur_res.pop_back();
                    cur_res.pop_back();
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r - 1])
                        r--;

                    l++;
                    r--;
                }
            }

            return;
        }
        else
        {

            for (int i = 0; i < len - n + 1; i++)
            {
                if (i > 0 && nums[i] == nums[i - 1])
                    continue;
                vector<int> nums_new;
                nums_new.insert(nums_new.end(), nums.begin() + i + 1, nums.end());

                cur_res.push_back(nums[i]);
                nSum(nums_new, n - 1, target - nums[i], cur_res, results);
                cur_res.pop_back();
            }
        }
    }
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<int> cur_res;
        nSum(nums, 4, target, cur_res, res);
        return res;
    }
};