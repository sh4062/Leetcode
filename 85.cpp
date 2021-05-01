class Solution {
public:
    int res  = 0;
    void f84(vector<int>row){
        stack<int>st;
        row.insert(row.begin(),0);
        row.push_back(0);
        for(int i = 0;i<row.size();i++){
            while(!st.empty()&&row[i]<row[st.top()]){
                int tmp = st.top();
                st.pop();
                if(st.size()>0)
                res = max(res,(i-st.top()-1)*row[tmp]);
                
            }
            st.push(i);
        }


    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size())return 0;
        vector<int>aux (matrix[0].size(),0);
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    aux[j]++;
                }
                else{
                    aux[j]=0;
                }
            }
            f84(aux);

        }
        return res;

    }
};
