class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)return 1;
        string bin = "";
        int n = N;
        while(n){
            int temp = n%2;
            bin = to_string (temp)+bin;
            n /=2;
        }
        for(auto &i:bin){
            if(i=='1')i='0';
            else i=('1');
        }
        //cout<<bin;
        int ss = bin.size()-1;
        int res =0;
        for(auto const &i:bin){
            if(i=='1') res+=pow(2,ss);
            ss--;
        }
        return res;
        
    }
};