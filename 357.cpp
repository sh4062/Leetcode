class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 0;
        vector<int>v(n+1,0);
        v[1]=10;
        for(int i = 2;i<=n;i++){
            int cur = 9,tmp = i;
            while(tmp>1){
                tmp--;
                cur*=10-tmp;
            }
            v[i]=cur+v[i-1];

        }
        return v[n];


    }
};
