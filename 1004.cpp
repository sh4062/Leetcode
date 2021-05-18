class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt=0,left=0,right=0,len=nums.size();
        while(right<len){
            if(nums[right]==0) ++cnt;
            ++right;
            if(cnt>k) {
                if(nums[left]==0) --cnt;
                ++left;
            }
        }
        return right-left;
    }
};
