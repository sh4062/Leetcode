class Solution {
public:
    int titleToNumber(string s) {
        long res=0;
        long c=1;
            for(int i=s.size()-1;i>=0;i--){
                res+=c*(s[i]-'A'+1);
                    c*=26;
            }
        return res;
    }
};
