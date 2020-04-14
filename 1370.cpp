class Solution {
public:
    string sortString(string s) {
        int l = s.size();
        string res = "";
        unordered_map<int,int>m;
        for(int i = 0;i<s.size();i++){
            m[i] = 0;
        }
       while(l>0){
            int sm =300;
            int sm_idx = 0;
            int la =0;
            int la_idx = 0;
            for(int i = 0;i<s.size();i++){
                if(int(s[i])<sm&&m[i]==0){
                    sm = int(s[i]);
                    sm_idx = i;
                }
                if(int(s[i])>la&&m[i]==0){
                    la = int(s[i]);
                    la_idx = i;
                }
                
            }
            l--;
            m[sm_idx]=1;
            res.push_back(s[sm_idx]);
            int s1 = sm+1;
            while(s1!=la+1){
                for(int i = 0;i<s.size();i++){
                    if(s1==int(s[i])&&m[i]==0){
                        s1=int(s[i]);
                        m[i] = 1;
                        res.push_back(s[i]);
                        l--;
                        break;
                        
                    }
                   
                }
                 s1++;
                
                
            }
            
           if(l==0)break;
        sm = 300;
            la = 0;
           for(int i = 0;i<s.size();i++){
                if(int(s[i])<sm&&m[i]==0){
                    sm = int(s[i]);
                    sm_idx = i;
                }
                if(int(s[i])>la&&m[i]==0){
                    la = int(s[i]);
                    la_idx = i;
                }
                
            }
            l--;
            m[la_idx]=1;
            res.push_back(s[la_idx]);
            int s2 = la-1;
            while(s2!=sm-1){
                for(int i = 0;i<s.size();i++){
                    if(s2==int(s[i])&&m[i]==0){
                        s2=int(s[i]);
                        m[i] = 1;
                        res.push_back(s[i]);
                        l--;
                        break;
                        
                    }
                    
                }
                s2--;
                
            }
        }
        return res;
    }
};