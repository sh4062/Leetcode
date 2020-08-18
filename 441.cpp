class Solution {
public:
    int arrangeCoins(int n) {
        //string t=¤;
        int c=1;
        int l=0;
        if(n==1){return 1;}
        while(n>c){
            //for(int i=0;i<c-1;i++){
                //cout<<t<<" ";
            //}
            //cout<<c<<endl;
            n-=c;
            c++;
            l++;
        }
        if(n==c){
            return l+1;
            
        }else{return l;}
    }
};
