class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        for(int i=0;i<mat.size();i++){
            
                res+=mat[i][i];
                if(mat.size()-1-i!=i)
                res+=mat[mat.size()-1-i][i];

            
        }
        return res;

    }
};
