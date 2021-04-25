class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp1;
        vector<int>m;
        for(auto i:s){
            mp1[i]++;        }
        for(auto i:mp1){
            m.push_back(i.second);

        }
        sort(m.begin(),m.end());
        int res = 0;
        for(int i=m.size()-2;i>=0;i--){
            if(m[i]>=m[i+1]){
                int tmp = m[i];
                m[i]=max(0,m[i+1]-1);
                res+=tmp-m[i];
            }
        }
        return res;

    }
};
