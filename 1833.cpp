class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        if(coins<costs[0])return 0;
        int res = 0;
        int idx = 0;
        for(idx;idx<costs.size();idx++){
            if(coins<0)break;
            coins-=costs[idx];
            
            res++;
        }
        if(coins<0)res--;
        return res;

    }
};
