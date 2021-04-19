class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<2)return 0;
        int l=nums.size();
        int res=0;
        int left = 0,right = 0;
        int p = 1;
        while(right<l){
            p*=nums[right];
            right++;

            while(p>=k){
                p/=nums[left];
                left++;
            }
            res+=right-left;
        }
        return res;

    }
};
