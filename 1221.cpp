class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0;
        int a  = 0;
        for(auto i:s){
            if(i=='L')
            a--;
            if(i=='R')
            a++;
            if(a==0)
            cnt++;
        }
        return cnt;

    }
};
