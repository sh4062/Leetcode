class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>row;
        vector<int>col;
        for(int i = 0;i<matrix.size();i++){
            row.push_back(*min_element(matrix[i].begin(),matrix[i].end()));
        }
        for(int i = 0;i<matrix[0].size();i++){
            int m = 0;
            for(int j =0;j<matrix.size();j++){
                m=max(m,matrix[j][i]);
            }
            col.push_back(m);
        }
    vector<int>res;
    for(int i = 0;i<row.size();i++){
        for(auto j:col){
            if(row[i]==j){
                res.push_back(j);
            }
        }
    }
    return res;
    }
    
};
