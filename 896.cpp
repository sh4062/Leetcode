class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()<2)return true;
        int f = 0;
        int i = 1;
        for(i = 1;i<nums.size();i++){
                if(nums[i]<nums[i-1]){
                    f=1;
                    break;
                }
                if(nums[i]>nums[i-1]){
                    f=2;
                    break;
                }
            }
        if(f==1){
            for(i;i<nums.size();i++){
                if(nums[i]>nums[i-1])return false;
            }

        }else if(f==2){
            for(i ;i<nums.size();i++){
                if(nums[i]<nums[i-1])return false;
            }
        }
        return true;

    }
};
