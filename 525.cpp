class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int>presum(nums.size()+1,0);
        for(int i = 1;i<=nums.size();i++){
            if(nums[i-1]==0)nums[i-1]=-1;
            presum[i]=presum[i-1]+nums[i-1];
        }
        unordered_map<int,int>mp;//值 坐标 
        int res = 0;
        mp[0]=0;
        for(int i =1;i<=nums.size();i++){
            if(mp.find(presum[i])==mp.end()){
                mp[presum[i]]=i;
            }
            if(mp.count(presum[i])){
                 res=max(i-mp[presum[i]],res);
            }
        }
        return res;

    }
};
