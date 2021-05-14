class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {

        int ml = m,mr =n;
        for(auto o:ops){
            ml=min(ml,o[0]);
            mr=min(mr,o[1]);
        }
        
        return ml*mr;

    }
};
