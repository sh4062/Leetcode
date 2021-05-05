class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0;i<nums.size();i++){
            while(nums[i]!=i+1){
                swap(nums[nums[i]-1],nums[i]);
                if(nums[nums[i]-1]==nums[i])break;
            }
        }

        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=i+1){
                res.push_back(nums[i]);
            }
        }
        return res;

    }
};
