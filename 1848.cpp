class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        vector<int>v;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==target){
                v.emplace_back(i);
            }
        }
        int res = INT_MAX;
        for(int i = 0;i<v.size();i++){
            if(abs(v[i]-start)<res){
                res=abs(v[i]-start);
            }
        }
        return res;

    }
};
