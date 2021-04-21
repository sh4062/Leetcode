class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int>up(nums.size(),1);
        vector<int>down(nums.size(),1);
        for(int i = 1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                up[i] = down[i-1]+1;
                down[i] = down[i-1];

            }else if(nums[i]>nums[i-1]){
                down[i] = up[i-1]+1;
                up[i] =up[i-1]; 

            }
            else{
                down[i] = down[i-1];
                 up[i] =up[i-1]; 


            }

        }
        int res = 0;
        for(int i = 0;i<nums.size();i++){
            res= max(res,up[i]);
            res= max(res,down[i]);
        }
 
        return res;

    }
};
