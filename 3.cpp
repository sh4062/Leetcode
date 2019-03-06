class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        if(s.size()<2)return 1;
        vector<int> d(256,0);
        int i=0,j=-1,res=0;
        for(i=0;i<s.size();i++){
          // cout<<j<<" "<<d[s[i]]<<endl;
            ++d[s[i]];
            if(d[s[i]]>1){
                while(d[s[i]]>1){
                    j++;
                    --d[s[j]];
                }
            }
         res=max(res,i-j);
        }
        return res;
                      }
    
};

    
