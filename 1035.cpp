class Solution {
public:
    int res = 0;
    map<pair<int,int>,int>mp;
    int dfs(int index1,int index2,vector<int>& A, vector<int>& B){

        
        if(index1>=A.size()||index2>=B.size()){
            
            return 0;
        }

        if(mp.count({index1,index2}))return mp[{index1,index2}];
        //for(int i = index1;i<A.size();i++){
        int r= 0;
            for(int j = index2;j<B.size();j++){
                if(A[index1]==B[j]){
                    r=max(r,1+dfs(index1+1,j+1,A,B));
                    break;
                }
            }
        //}
        r=max(r,dfs(index1+1,index2,A,B));
        mp[{index1,index2}]=r;
        return r;
        

    }
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        if(m>n)swap(A,B);

        res=dfs(0,0,A,B);
        return res;


    }
};
