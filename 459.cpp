class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size()/2;
        for(int i = 1;i<len+1;i++){
            
            if(s.size()%i!=0)continue;
            string cur = s.substr(0,i);
            //cout<<cur<<endl;
            int flag = 1;
            for(int j = i;j<s.size();j+=i){
                //cout<<s.substr(j,i)<<endl;
                if(s.substr(j,i)!=cur){
                    flag = 0;
                    break;
                }
            }
            if(flag) return true;
            
               
            
        }
        return false;

    }
};
