class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if(M.empty()){
            return M;
        }
        int rows = M.size();
        int cols = M[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        for(int i=0 ; i<rows ; i++){
            for(int j=0 ; j<cols ; j++){
                int sum = M[i][j];
                int count = 1;
                if(i-1 >= 0){
                    if(j-1 >= 0){
                        sum += M[i-1][j-1];
                        count++;
                    }
                    if(j+1 < cols){
                        sum += M[i-1][j+1];
                        count++;
                    }
                    sum += M[i-1][j];
                    count++;
                }
                if(i+1 < rows){
                    if(j-1 >= 0){
                        sum += M[i+1][j-1];
                        count++;
                    }
                    if(j+1 < cols){
                        sum += M[i+1][j+1];
                        count++;
                    }
                    sum += M[i+1][j];
                    count++;
                }
                if(j-1 >= 0){
                    sum += M[i][j-1];
                    count++;
                }
                if(j+1 < cols){
                    sum += M[i][j+1];
                    count++;
                }
                result[i][j] = sum/count;
            }
        }
        return result;
    }
};
