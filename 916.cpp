class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string>res;
        vector<int>mp1(26,0);
        for(int i = 0;i<B.size();i++){
            vector<int>tmp(26,0);
            for(auto j:B[i]){
                tmp[j-'a']++;
            }
            for(int k = 0;k<26;k++){
                mp1[k]=max(mp1[k],tmp[k]);
            }
        }
        for(auto i:A){
            vector<int>tmp(26,0);
             for(auto j:i){
                tmp[j-'a']++;
            }
            int flag = 1;
            for(int k = 0;k<26;k++){
                if(mp1[k]!=0&&tmp[k]<mp1[k]){
                    flag=0;
                }
            }
            if(flag)res.emplace_back(i);
        }
        return res;

    }
};
