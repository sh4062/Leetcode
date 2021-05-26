class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        vector<pair<int,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){if(a.second!=b.second)return a.second<b.second;else return a.first>b.first;});
        vector<int>res;
        for(auto i:v){
            for(int j=0;j<i.second;j++)
            res.push_back(i.first);
        }
        return res;

    }
};
