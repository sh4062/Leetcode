class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l =0;
        int r =matrix[0].size()*matrix.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            //cout<<mid<<endl;
            if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]==target){
                return true;
            }else if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]<target){
                l=mid+1;

            }else if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]>target){
                r=mid-1;
                
            }
        }
        return false;

    }
};
