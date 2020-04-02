class Solution {
public:
    bool canWinNim(int n) {
        // if(n==0|n==1||n==2||n==3)return true;
        // if(n==4)return false;
        // if(canWinNim(n-1)==true&canWinNim(n-2)==true&canWinNim(n-3)==true
        //   )return false;
        // return true;
        return !(n%4==0);
    }
};