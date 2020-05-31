class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        set <int> res;
        unordered_map<int,int> m;
        map<int,vector<int>>mm;
        for(auto const & i:nums){
            m[i]++;
        }
        for(auto const & i:m){
            if(mm.find(i.second)==mm.end()){
             mm[i.second]=vector<int>();
            mm[i.second].push_back(i.first);}
            else{
                mm[i.second].push_back(i.first);
            }
        }
        for(map<int,vector<int>>::reverse_iterator rit=mm.rbegin();rit!=mm.rend(),res.size()<k;rit++) {
            
            for(auto const&j:rit->second){
                            
            res.insert(j);
            }
            
        }

        return vector<int>(res.begin(),res.end());
        
        
    }
};