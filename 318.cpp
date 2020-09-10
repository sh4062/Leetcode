class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size()<1)return 0;
        sort(words.begin(),words.end(),[](string a,string b){return a.size()<b.size();});
        int res=0;
        vector<unordered_map<char,int>>vv;
        for(auto i : words){
            unordered_map<char,int>t;
            for(auto j:i){
                t[j]++;
            }
            vv.emplace_back(t);
        }
        for(int i =0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                int flag =0;
                for(auto x:words[j]){
                    if(vv[i].count(x)){
                        flag=1;
                        break;
                    }
                }
                if(flag)continue;
                res=max(res,int(words[i].size()*words[j].size()));
            }
        }
        return res;
    }
};
