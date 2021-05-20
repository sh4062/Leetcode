class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>res;
        unordered_map<string,int>mp;
        for(auto i:words)mp[i]++;
        vector<pair<string,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](pair<string,int>a,pair<string,int>b){if(a.second!=b.second)return a.second>b.second;else return a.first<b.first;});
        for(int i = 0;i<k;i++){
            res.push_back(v[i].first);
        }
        return res;

    }
};
