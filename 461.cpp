class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        int z=x^y;
        while(z){
            cnt+=z%2;
            z/=2;
        }
        return cnt;

    }
};
