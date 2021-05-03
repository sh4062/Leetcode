class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10)return {};
        vector<string> res;
        int index = 0;
        unordered_map<string,int>mp;
        for(int i = 0;i<=s.size()-10;i++){
            string tmp = s.substr(i,10);
            mp[tmp]++;
            

        }
        for(auto i:mp){
            if(i.second>=2){
                res.emplace_back(i.first);
            }
        }
        return res;

    }
};
