class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = nums[nums.size()-1];
        res*= nums[nums.size()-2];
        res*= nums[nums.size()-3];
        res=max(res, nums[0] * nums[1] * nums[nums.size()-1]);
        return res;
    }
};
