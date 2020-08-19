class Solution {
public:
    int countOne(int n){
        int c=0;
        while(n){
        c+=1;
        n&=(n-1);
        }
        return c;
    }
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i =0;i<=num;i++)
        res.push_back(countOne(i));
        return res;
    }
};
