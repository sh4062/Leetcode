class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift=0;
        while(m!=n){
            // cout<<m<<endl;
            // cout<<n<<endl;
            m>>=1;
            n>>=1;
            shift++;
        }
        return m<<shift;
    }
};
