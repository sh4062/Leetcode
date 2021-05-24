class Solution {
public:

    bool isValid(string s) {
        if(s=="abc")
        return true;
        if(s.size()%3!=0){
            return false;
        }
        if(s[0]!='a')return false;
        int t = s.size()/3;
        // while(t--){
        for(int i = 0;i<s.size()-3;i++){
            if(s.substr(i,3)=="abc"){
                return isValid(s.substr(0,i)+s.substr(i+3,s.size()-i-3));
            }
        }
        // }
        // if(s=="abc")
        return false;

    }
};
