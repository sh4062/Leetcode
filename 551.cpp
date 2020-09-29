class Solution {
public:
    bool checkRecord(string s) {
        int maxL = 0;
        int aSum=0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='A'){
                aSum++;
            }
            if(aSum>=2)return false;
            if(s[i]=='L'){
                int j =i+1;
                for(j;j<s.size();j++){
                    if(s[j]!='L')
                        break;
                }
                maxL=max(maxL,j-i);
                i+=j-i-1;
            }
            
        }
        if(maxL>2)
            return false;
        return true;
    }
};
