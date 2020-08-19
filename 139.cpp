class Solution {
public:
    int flag=0;
    string ss;
    string b;
    vector<string>dict;
    unordered_map<string,int>mp;
    void dfs(int a){
        if(a>=ss.size()){flag=1;return;}
        if(mp.find(b)!=mp.end()){
          return;
        }
        for(int i = 0;i<dict.size();i++){
            if(dict[i].size()+a>ss.size())continue;
            if(ss.substr(a,dict[i].size()).compare(dict[i])==0){
                b=b+ss.substr(a,dict[i].size());
                dfs(a+dict[i].size());
                b=b.substr(0,b.size()-dict[i].size());
                mp[b]++;
            }
        }
        
       
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        ss=s;
        dict=wordDict;
       // int len=wordDict.size();
       // int len2=s.size();
       dfs(0);
       return flag;

    }
};
