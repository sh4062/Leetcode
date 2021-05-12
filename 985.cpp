class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int>res;
        int all=0;
         for(int j = 0;j<A.size();j++){
             if(A[j]%2==0)
               all+=A[j];
         }
        //cout<<all;
        for(const auto& i:queries){
            int f = 0;
            int tmp = A[i[1]];
            if(A[i[1]]%2==0)f=1;
            A[i[1]]+=i[0];
            if(f){
                if(A[i[1]]%2==0){
                    all-= tmp;
                    all+= A[i[1]];
                }else{
                    all-=tmp;
                }
            }else{
                if(A[i[1]]%2==0)all+= A[i[1]];
            }
            
            res.push_back(all);

        }
        return res;

    }
};
