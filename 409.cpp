class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        int cnt = 1;
        for(auto i:mp){
            if(i.second%2==0){
                cnt+=i.second;
            }else{
                cnt+=i.second/2*2;
            }
        }
        return cnt>s.size()?s.size():cnt;

    }
};
