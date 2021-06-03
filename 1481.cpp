class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }
        vector<pair<int,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](pair<int,int>a,pair<int,int>b){return a.second<b.second;});
        int res = 0;
        for(int i = 0;i<v.size()&&k>=0;i++){
            k-=v[i].second;
            if(k>=0)
            res++;
        }
        return v.size()-res;



    }
};
