class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxf = 0;
        for(auto i:nums){
            mp[i]++;
            maxf = max(maxf,mp[i]);
        }
        int right = 0,left = 0;
        int res = nums.size();
        unordered_map<int,int>win;
        while(right<nums.size()){
            win[nums[right]]++;
            int cur = nums[right];
            right++;
            //
            while(win[cur]==maxf){
                res=min(res,right-left);
                win[nums[left]]--;
                left++;
            }
            


        }
        return res;                                     

    }
};
