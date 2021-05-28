class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>>res;
        if(A.size()==0||B.size()==0)return res;
        vector<int> tmp(2);
        int cnt = 0;
        for(int i=0;i<A.size()&&cnt<B.size();)
        {
            if(A[i][0]>B[cnt][1])
            {
                cnt++;
            }
            else if(A[i][1]<B[cnt][0])
            {
                i++;
            }
            else if(A[i][1]<B[cnt][1])
            {
                tmp[0] = max(A[i][0],B[cnt][0]);
                tmp[1] = A[i][1];
                res.push_back(tmp);
                i++;
            }
            else
            {
                tmp[0] = max(A[i][0],B[cnt][0]);
                tmp[1] = B[cnt][1];
                res.push_back(tmp);
                cnt++;
            }
        }
        return res;

    }
};
