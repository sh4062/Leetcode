class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)return false;
        if(s.size()==k)return true;
        vector<int>v(26,0);
        for(auto i:s){
            v[i-'a']++;
        }
        int cnt = 0;
        for(auto i:v){
            if(i%2!=0)cnt++;
        }
        if(cnt>k)return false;
        return true;
    }
};
