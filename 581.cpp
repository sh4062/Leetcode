class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int>st;
        int res = 0;
        int  l = nums.size()+1;
        int  r = 0;
        for(int i = 0;i<nums.size();i++){
            while(!st.empty()&&nums[i]<nums[st.top()]){
                l=min(l,st.top());
                st.pop();

            }
            st.push(i);
        }
        if(l==nums.size()+1)l=1;
        while(!st.empty())st.pop();
        for(int i = nums.size()-1;i>=0;i--){
            while(!st.empty()&&nums[i]>nums[st.top()]){
                r=max(r,st.top());
                st.pop();

            }
            st.push(i);
        }
        return r-l+1;

    }
};
