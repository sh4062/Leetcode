class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        map<int,int>mp;
        for(auto i:candies){
            mp[i]++;
        }
        //vector<pair<int,int>>smp(mp.begin,mp.end());
        //sort(smp,[](pair<int,int>a,pair<int,int>b){return a.second>b.second()});
        int nn=candies.size()/2;
        int res = 0;
        while(nn){
        for(auto i:mp){
            if(nn==0)break;
            res++;
            if(i.second>0){
            i.second--;
            nn--;
            }
        }
        }
        if(res>mp.size())res=mp.size();
        return res;
    }
};
