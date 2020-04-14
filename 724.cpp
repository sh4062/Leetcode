class Solution {
public:

    int pivotIndex(vector<int>& nums) {
        
        if(nums.size()==0||nums.size()==1||nums.size()==2)return -1;
        int l = nums.size();
        int prefixSum = 0;
        int totalSum =0;
        
        for(int i = 0;i<nums.size();i++){
            totalSum+=nums[i];
            
            
        }
        if(totalSum-nums[0]==0)return 0;
        for(int i=0; i< nums.size()-1; i++)
        {
            prefixSum += nums[i];
            totalSum -= nums[i];
            
    // totalSum - PrefixSum = nextNumber then both right and left sum are equal to index = i+1(pivot)
            if(totalSum - prefixSum == nums[i+1])                                            
                return i+1;
        }        
        
 
        return -1;
        
    }
};