class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        multimap<int,int>mp;
        for(int i = 0;i<mat.size();i++){
            int cur = accumulate(mat[i].begin(),mat[i].end(),0);
            mp.insert({cur,i});
        }
        vector<int>res;
        int c =0;
        for(auto i:mp){
            res.push_back(i.second);
            c++;
            if(c==k)break;
        }
        return res;

    }
};
