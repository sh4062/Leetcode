class Solution {
public:
    bool rotateString(string A, string B) {
        int n=A.size();
        if(n!=B.size())return false;
        if(n==0)return true;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n-1;j++){
                swap(B[j],B[(j-1+n)%n]);
            }
            if(B==A)return true;
        }
        return false;
    }
};
