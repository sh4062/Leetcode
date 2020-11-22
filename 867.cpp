class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>>a(A[0].size(),vector<int>(A.size(),0));
        for(int i = 0;i<a.size();i++){
            for(int j = 0;j<a[0].size();j++){
                a[i][j]=A[j][i];
            }
        }
        return a;
    }
};
