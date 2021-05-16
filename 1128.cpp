class Solution {
public:
    map<pair<int,int>,int>mp;
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int cnt = 0,cnt2=0;
        for(auto i:dominoes){
            mp[{i[0],i[1]}]++;
            
        }
        for(auto i:mp){
            if(mp[{i.first.first,i.first.second}]>=2){
                int tmp =i.second;
                    
                    cnt+=tmp*(tmp-1)/2;
                
            }
            if((i.first.second!=i.first.first)&&mp.count({i.first.second,i.first.first})){
                cnt2+=i.second*mp[{i.first.second,i.first.first}];
            }

        }
        return cnt+cnt2/2;

    }
};
