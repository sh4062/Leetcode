class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)return  false;
        int m = matrix.size(),n = matrix[0].size();
        int low = 0,high = m;
        for(int i = 0;i<m;i++){
        //low = lower_bound(matrix.begin(),matrix.end(),target);
       if(binary_search(matrix[i].begin(),matrix[i].end(),target)){
                    return true;
                }
            
        }
        return false;
    }
};