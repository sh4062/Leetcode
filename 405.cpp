class Solution {
public:
    string toHex(int num) {
        int n  = num;
        string res;
        if(n==0)return string("0");
        if(n>0){
        while(n){
            int tmp = n%16;
            if(tmp<10)res+=('0'+tmp);
            if(tmp==10)res+='a';
            else if(tmp==11)res+='b';
            else if(tmp==12)res+='c';
            else if(tmp==13)res+='d';
            else if(tmp==14)res+='e';
            else if(tmp==15)res+='f';
            n/=16;
            
        }
        }else{
            uint a = n;
            while(a){
            int tmp = a%16;
            if(tmp<10)res+=('0'+tmp);
            if(tmp==10)res+='a';
            else if(tmp==11)res+='b';
            else if(tmp==12)res+='c';
            else if(tmp==13)res+='d';
            else if(tmp==14)res+='e';
            else if(tmp==15)res+='f';
            a/=16;
        }
        }
        reverse(res.begin(),res.end());
        return res;

    }
};
