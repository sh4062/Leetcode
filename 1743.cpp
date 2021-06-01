class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>mp;
        vector<int>res;
        for(auto i:adjacentPairs){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        unordered_set<int>S;
        int cnt=0;
        int end;
        for(auto i:mp){
            if(i.second.size()==1&&cnt==0){
                res.push_back(i.first);
                cnt++;
            }else if(i.second.size()==1){
                end=i.first;
            }
        }
        S.insert(res[0]);
        int cur = 0;
        while(S.size()<mp.size()){
            for(auto i:mp[res[cur]]){
                if(S.find(i)==S.end()){
                    S.insert(i);
                    res.push_back(i);
                    cur++;
                }
            }
        }
        return res;


    }
};
