class Solution {
public:
    int minOperations(string s) {
        int n =s.size();
        int i = 1;
        int j = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for(auto ss:s){
            if(ss-'0'!=i){
                cnt1++;

            }
            if(ss-'0'!=j){
                cnt2++;
            }
            i^=1;
            j^=1;
        }
        return min(cnt1,cnt2);

    }
};
