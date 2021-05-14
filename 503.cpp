class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int maxn=*max_element(nums.begin(),nums.end());
        vector<int>res(nums.size(),-1);
        // stack<int>st;
        // for(int i = 0;i<nums.size()*2;i++){
        //     int cur = nums[i%nums.size()];

        //     while(!st.empty()&&nums[st.top()]<cur){
        //         res[st.top()]=cur;
        //         st.pop();

        //     }
        //     if(i<nums.size())
        //     st.push(i);
        // }
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==maxn){
                res[i]=-1;
            }else{
                for(int j = i+1;j<i+nums.size();j++){
                    if(nums[j%nums.size()]>nums[i]){
                    res[i]=nums[j%nums.size()];
                    break;}
                }
            }
        }
        return res;

    }
};
