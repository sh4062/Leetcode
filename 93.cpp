class Solution {
public:
    vector<string> res;
    vector<int>tmp;
    void dfs(string s,int cnt,int idx){
        if(cnt==4&&idx==s.size()){
            string ip;
            for(int i = 0;i<4;i++){
                ip+=((to_string(tmp[i])));
                if(i!=3)
                ip+=(".");
            }
            res.push_back(move(ip));

        }
        
        if(cnt==4)return;
        if(idx==s.size())return;
        if(s[idx]=='0'){
            tmp[cnt]=0;
            dfs(s,cnt+1,idx+1);
            return;
        }
        int t = 0;
        for(int i = idx;i<s.size();i++){
            t = t*10+(s[i]-'0');
            if(t>=0&&t<=255){
               tmp[cnt]=t;
               dfs(s,cnt+1,i+1);
            }
            else{
                break;
            }
            
        }
    }
    vector<string> restoreIpAddresses(string s) {
        tmp.resize(4,0);
        dfs(s,0,0);
        return res;

    }
};
