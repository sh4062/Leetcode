class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0,right =0;
        int res = 0;
        int sum = 0;
        unordered_set<int>S;
        int n = nums.size();
        while(right<n){
           if (!S.count(nums[right])) {

                sum += nums[right];
                res = max(res, sum);
                S.insert(nums[right]);
                right++;
                continue;
            }
            
            while (S.count(nums[right])) {
                
                S.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            

        }
        return res;

    }
};
