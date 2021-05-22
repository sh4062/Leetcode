class Solution {
public:
    bool hasAlternatingBits(int n) {
        int a=n%2;
        int cnt = 0;
        n-=n%2;
        n/=2;
        while(n){
            if(n%2==a)return false;
            else{
                if(a==0)a=1;
                else a = 0;
            }
            n-=n%2;
            n/=2;

            
        }
        return true;

    }
};
