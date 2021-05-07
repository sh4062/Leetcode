class Solution {
public:
    bool dfs(string &s,int index,int cnt,unordered_set<string>&S){
        if(index>=s.size()){
            return cnt>1;
        }
        for(int i = index;i<s.size();i++){
            string tmp = s.substr(index,i-index+1);
            if(S.count(tmp)&&dfs(s,i+1,cnt+1,S)){
                return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if(words.size()<2)return {};
        vector<string>res;
        unordered_set<string>S(words.begin(),words.end());
        for(int i = 0;i<words.size();i++){
            if(words[i].size()==0)continue;
            if(dfs(words[i],0,0,S)){
                res.emplace_back(words[i]);
            }
        }
        return res;


    }
};
