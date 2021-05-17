class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int res = 0;
        vector<pair<int,int>>v;
        for(int i = 0;i<difficulty.size();i++){
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        for(int i = 1;i<v.size();i++){
            if(v[i-1].second>v[i].second){
                v[i].second=v[i-1].second;
            }

        }
        for(auto i:worker){
            int a = upper_bound(v.begin(),v.end(),pair<int,int>{i,100000})-v.begin();
            //cout<<a<<endl;
            if(a>1)
            res+=v[a-1].second;
            else{
                if(v[0].first<=i)res+=v[0].second;
                else
                res+=0;
            }
        }
        return res;

    }
};
