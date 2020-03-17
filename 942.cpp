class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res(S.length()+1,0);
        int h=S.length();
        int l = 0;
         if(S[0]=='I'){res[0]=l;l++;}else{res[0]=h;h--;}
        for(int i = 1;i<S.length()+1;i++){
            if(S[i]=='I'){
                
                res[i]=l;
                l++;
                
                
            }else{
                res[i]=h;
                h--;
                
            }
        }
        return res;
        
    }
};