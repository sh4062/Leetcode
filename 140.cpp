class Solution {
public:
    vector<string> res;
    int flag=0;
    string ss;
    string b;
    vector<string> bb;
    vector<string>dict;
    unordered_map<string,int>mp;
    void dfs(string a){
       // cout<<a<<endl;
        if(a.compare(ss)==0){
            string tmp;
            for(int i=0;i<bb.size()-1;i++)tmp=tmp+bb[i]+" ";
            tmp=tmp+bb[bb.size()-1];
            res.push_back(tmp);
            return;}//
           if(mp.find(a)!=mp.end()&&mp[a]==-1){
           return ;
         }
        for(int i = 0;i<dict.size();i++){
            if(ss.substr(a.size(),dict[i].size()).compare(dict[i])==0){
               
                bb.push_back(dict[i]);
                int sov=res.size();
                //cout<<dict[i]<<endl;
                //b+ss.substr(a.size(),dict[i].size());
                dfs(a+dict[i]);
                if(res.size()==sov)mp[a+dict[i]]=-1;
                //b.substr(0,b.size()-dict[i].size());
                bb.pop_back();
                
                //if(ss.compare(b)!=0)
                
                //cout<<b<<endl;
            }
        }
       
        //mp[a]=0;
        
       
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ss=s;
        //sort(wordDict.begin(),wordDict.end());
        dict=wordDict;
        string sss="";
       // int len=wordDict.size();
       // int len2=s.size();
       dfs(sss);
       return res;

    }
};
