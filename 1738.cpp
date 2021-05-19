class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> v(m+1,vector<int>(n+1,0));
        vector<int>res;
        for(int i =1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                v[i][j]=matrix[i-1][j-1]^v[i][j-1]^v[i-1][j]^v[i-1][j-1];
                res.push_back(v[i][j]);
            }
        }
        sort(res.begin(),res.end());
        return res[res.size()-k];
        

    }
};
