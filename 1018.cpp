class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool>res;
        int tmp = 0;
        for(int i = 0;i<A.size();i++){
            
            
            tmp = (tmp*2+A[i])%5;
            if(tmp%5==0)res.push_back(true);
            else res.push_back(false);

        }
        return res;

    }
};
