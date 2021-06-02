class Solution {
public:
    int maxVowels(string s, int k) {
        int left=0,right = 0;
        int cur = 0;
        int res = 0;
        while(right<s.size()){
            if(s[right]=='a'||s[right]=='e'||s[right]=='i'||s[right]=='o'||s[right]=='u'){
                cur++;
                
            }
            right++;
            while(right-left>k){
                if(s[left]=='a'||s[left]=='e'||s[left]=='i'||s[left]=='o'||s[left]=='u')
                cur--;
                left++;
            }
            if(cur==k)return k;
            res=max(res,cur);

        }
        return res;

    }
};
