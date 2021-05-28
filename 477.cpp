class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<pair<int,int>>bits(32,{0,0});
        for(auto n:nums){
            for(int i = 0;i<32;i++){
            if((n&1)==1)
            bits[i].second+=1;
            else bits[i].first+=1;
            n>>=1;
            }
        }
        int res = 0;
        for(auto i:bits){
            //cout<<i.first<<i.second<<endl;
            res+=i.first*i.second;
        }
        return res;

    }
};
