class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        for(int i = 0; i < nums.size()-1; ++i) 
            if(nums[i] == 0 && nums[i+1] == 0) return true;
        unordered_map<int,int>mp;
        int prefixsum = 0;
        mp[0] = -1;
        for(int i = 0;i<nums.size();i++){
            prefixsum+=nums[i];
            int mod = prefixsum%k;
            //cout<<mod<<endl;
            if(mp.find(mod)!=mp.end()){
                if(i-mp[mod]>1)
                    return true;
            }
            else mp[mod]=i;


            //presum[i+1]=presum[i]+nums[i];
        }
        // for(int i = 0;i<nums.size();i++){
        //     for(int j = 0;j<i;j++){
        //         if((presum[i+1]-presum[j])%k==0){
        //             return true;
        //         }

        //     }
        // }
        return false;

    }
};
