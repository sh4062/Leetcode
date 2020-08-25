class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<=1)return 0;
        if(nums.size()==2){
            if(nums[0]>nums[1])return 0;
            else return 1;
        }
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1){
                if(nums[i]>nums[i-1]&&nums[i]>nums[0]){
                    res=i;
                    return res;
                }
                
            }else if(i==0){
                if(nums[i]>nums[i+1]&&nums[i]>nums[nums.size()-1]){
                    res=i;
                    return res;
                }
            }else{
                 if(nums[i]>nums[i+1]&&nums[i]>nums[i-1]){
                    // cout<<i;
                    res=i;
                    return res;
                }
                
            }
        }
        return 0;
    }
};
