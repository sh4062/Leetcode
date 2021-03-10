class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i = 0;
        int cur;
        while(i<nums.size()){
            cur=nums[i];
            if(nums[i]!=i+1){
                swap(nums[i],nums[nums[i]-1]);
                if(nums[i]==cur)i++;

            }else{
                i++;
            }
        }

        for(int j=0;j<nums.size();j++){
            if(nums[j]!=j+1){
                return{nums[j],j+1};
            }

        }
        return nums;

    }
};
