class Solution {
public:
    int fib(int N) {
        if(N==0)return 0;
        if(N==1)return 1;
        int p = 0, q = 1;
        int res = 0;
        for(int i = 1;i < N; i++){
            res = p + q;
            p = q;
            q = res;
        }
        return res;
        
    }
};