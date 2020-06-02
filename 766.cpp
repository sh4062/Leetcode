class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int s = matrix.size();
        int ss = matrix[0].size();
        if(s==1||ss==1)return true;
        for(int i = 0;i<ss;i++){
            int c = matrix[0][i];
            int ii = 2;
            int j = i+2;
            
            while(j<=ss&&ii<=s){
            //cout<<matrix[ii-1][j-1];    
                if(matrix[ii-1][j-1]!=c){
                    return false;
                }
                else{
                    ii++;
                    j++;
                }
                
            }
        }
        if(s>=3){
        for(int i = 1;i<s;i++){
            int c = matrix[i][0];
           
            int ii = i+2;
            int j = 2;
            //cout<<j;
            while(j<=ss&&ii<=s){
                cout<<matrix[ii-1][j-1];   
                if(matrix[ii-1][j-1]!=c){
                    //cout<<matrix[ii-1][j-1];   
                    return false;
                }
                else{
                    ii++;
                    j++;
                }
                
            }
        }
            }
        return true;
    }
};