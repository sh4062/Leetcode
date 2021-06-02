class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int ,int>mp1;
        unordered_map<int ,int>mp2;
        for(auto i:target){
            mp1[i]++;
        }
        for(auto j:arr){
            mp2[j]++;
        }
        for(auto i:mp1){
            if(mp2[i.first]!=i.second)return false;
        }
        return true;


    }
};
