class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        unordered_map<char,int>mp1;
        for (int i = 0; i < S.size(); i ++) {
        mp1[S[i]] = i;
        }
        int s = 0,e=0;
        for(int i = 0;i<S.size();i++){
            e = max(e,mp1[S[i]]);
            if(i==e){
                res.push_back(e-s+1);
                s=i+1;
            }
        }
        return res;

    }
};
