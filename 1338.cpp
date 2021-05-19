class Solution {
public:
    unordered_map<int,int>v;
    int minSetSize(vector<int>& arr) {
        for(auto i:arr){
            v[i]++;
        }
        int t = arr.size()/2;
        int cur =0;
        int res = 0;
        vector<pair<int,int>>vv(v.begin(),v.end());
        sort(vv.begin(),vv.end(),[](pair<int,int>a,pair<int,int>b){return a.second>b.second;});
        while(cur<t){
            cur+=vv[res].second;
            res++;
        }
        return res;

    }
};
