class Solution {
public:
    int minMoves2(vector<int>& nums) {
        unordered_map<int,int>mp;

        long int res = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            long int tmp = 0;
            for(auto j:nums){
                 tmp+=abs(nums[i]-j);
         }
         res=min(res,tmp);

        }
        return res;

    }
};
