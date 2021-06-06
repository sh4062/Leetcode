class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>v(26,0);
        for(auto i:chars){
            v[i-'a']++;
        }
        int res = 0;
        for(auto w:words){
            vector<int>tmp(26,0);
            int flag = 0;
            for(auto ww:w){
                tmp[ww-'a']++;
            }
            for(int i = 0;i<26;i++){
                if(v[i]<tmp[i]){
                    flag=1;
                }
            }
            if(flag==0)res+=w.size();
        }
        return res;

    }
};
