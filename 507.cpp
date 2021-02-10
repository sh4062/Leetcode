class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1)return false;
        int sq=int(sqrt(num));
        int res=1;
        for(int i = 2;i<=sq;i++){
            if(num%i==0){
                res+=i;
                res+=num/i;
            }
        }

        return res==num;

    }
};
