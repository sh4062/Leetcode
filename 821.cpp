class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res(s.size(),INT_MAX);
        int pre = -1;
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                res[i]=0;
                pre = i;
            }else{
                if(pre!=-1){
                    res[i]=i-pre;
                }

            }
            
        }
        for(int i=s.size()-1;i>=0;i--){
           if(s[i]==c){
                res[i]=0;
                pre = i;
            }else{
                if(pre!=-1){
                    res[i]=min(res[i],abs(pre-i));
                }

            }
            
        }
        return res;
    }
};
