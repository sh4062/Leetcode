class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int two = INT_MIN;
        vector<int>st;
        for(int k = nums.size()-1;k>=0;k--){
            if(two>nums[k])return true;
            while(st.size()>0&&nums[k]>nums[st.back()]){
                two = nums[st.back()];
                st.pop_back();
            }
            st.push_back(k);
        }

        return false;

    }
};
