class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        
        int pre = nums[0];
        int cur = pre;
        int res = cur;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]<=pre){
                pre=nums[i];
                cur=pre;
            }
            else{
                cur+=nums[i];
                res=max(res,cur);
                pre=nums[i];

            }

            


        }
        return res;

    }
};
