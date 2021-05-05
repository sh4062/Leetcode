class Solution {
public:
    int findNthDigit(int n) {
        if(n<10)return n;
        if(n==10)return 1;
        int res = 0;
        int index = 0;
        long long nn = n;
        while(nn>0){
            nn-=9*pow(10,index)*(index+1);
            index++;
        }
        index--;
        nn+=9*pow(10,index)*(index+1);
        cout<<nn<<endl;
        int d = nn/(index+1);
        int left = nn%(index+1);
        cout<<d<<endl;
        int st = pow(10,index);
        st+=(d-1);
        cout<<st<<endl;
        cout<<index<<endl;
        cout<<left<<endl;
        if(left==0)
        res = to_string(st)[(index)]-'0';
        else{
            res = to_string(st+1)[(left-1)]-'0';
        }
        // cout<<to_string(st)[(index-1-left)]-'0';
        return res;

    }
};
