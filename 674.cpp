class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()<1)return 0;
        int res=1;
                    int t=1;

        for(int i =1;i<nums.size();i++){
           
                if(nums[i]>nums[i-1]){
                  //  cout<<t;
                    t++;
                }else{
                    
                    t=1;
                }
            
            res=max(res,t);
            }
        return res;
    }
};
