class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        for(int i = start;i<start+2*n;i+=2){
            res^=i;
        }
        return res;

    }
};
