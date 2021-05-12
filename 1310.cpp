struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>res;
        unordered_map<pair<int,int>,int,hash_pair>mp;
        int n = arr.size();
        for(const auto& i:queries){
            int c =0;
            if(mp.count({i[0],i[1]})){
                res.emplace_back(mp[{i[0],i[1]}]);
                continue;
            }
            for(int j=i[0];j<=i[1];j++){
                c^=arr[j];
            }
            mp[{i[0],i[1]}]=c;
            res.emplace_back(c);
        }
        return res;


    }
};
