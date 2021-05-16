class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }
        auto it = mp.rbegin();
        while(it!=mp.rend()){
            if(it->first==it->second){
                return it->first;
            }
            it++;
        }
        return -1;
        
    }
};
