class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini = INT_MIN;
        int midj=INT_MIN;
        int premax =INT_MAX;
        if(nums.size()<3)return false;
        if(nums[1]>nums[0]){
            mini=0;
            midj=1;
            premax=nums[1];
        }else{
            midj=-1;
            mini=1;
        }
        for(int i = 2;i<nums.size();i++){
            // cout<<premax<<endl;
            if(nums[i]>premax){
                return true;
            }
            if(nums[i]<nums[mini]){
                mini=i;
                midj=-1;
                continue;
            }
            if(nums[i]>nums[mini]){
                midj=i;
                premax=min(nums[midj],premax);
            }
            
        }
        // cout<<midj<<mini;


        return false;
    }
};
