class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int res =0;
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto i:mp){
            if(i.second==1)
            res+=i.first;
        }
        return res;

    }
};
