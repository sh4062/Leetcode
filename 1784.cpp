class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.size()<1)return false;
        if(s.size()==1&&s[0]=='1')return true;
        int c = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='1'){
                while(i+1<s.size()&&s[i+1]=='1'){
                      i++;
                }
                c++;
            }
            if(c>=2)return false;
        }
        if(c)
        return true;
        return false;

    }
};
