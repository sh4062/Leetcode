class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int cur = 0;
        //unordered_map<int,int>mp;
        vector<int>v(1001,0);
        for(auto i:trips){
            for(int j= i[1];j<i[2];j++){
                v[j]+=i[0];
                if(v[j]>capacity)return false;
            }
            
        }
        return true;

    }
};
