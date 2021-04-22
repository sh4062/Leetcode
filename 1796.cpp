class Solution {
public:
    int secondHighest(string s) {
        set<int>S;
        for(auto i:s){
            if(i-'0'<=9){
                S.insert(i-'0');
            }
            
        }
        if(S.size()<2)return -1;
        auto i = S.rbegin();


        return *(++i);

    }
};
