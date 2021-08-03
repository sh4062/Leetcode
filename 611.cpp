class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3)return 0;
        sort(nums.begin(),nums.end());
        
        int res =0;
        //左边
        for(int i = 0;i<nums.size()-2;i++){
            //右边
            for(int j = i+1;j<nums.size()-1;j++){
                int c = nums[i]+nums[j];
                int index = lower_bound(nums.begin()+j+1,nums.end(),c)-nums.begin();
                res+=index-(j+1);

            }

        }
        return res;

    }
};
