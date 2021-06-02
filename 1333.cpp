class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int,int>>res;
        for(auto r:restaurants){
            if(veganFriendly==1){
            if(r[2]==veganFriendly&&r[3]<=maxPrice&&r[4]<=maxDistance){
                res.push_back({r[0],r[1]});
            }}else{
                if(r[3]<=maxPrice&&r[4]<=maxDistance){
                res.push_back({r[0],r[1]});
            }

            }
        }
        sort(res.begin(),res.end(),[](pair<int,int>a,pair<int,int>b){if(a.second!=b.second)return a.second>b.second;else return a.first>b.first;});
        vector<int>ret;
        for(auto i:res){
            ret.push_back(i.first);
        }
        return ret;

    }
};
