class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==1&&citations[0]==0)return 0;
        if(citations.size()==1&&citations[0]>=1)return 1;
        int res=0;
        for(int i=1;i<=citations.size();i++){
            if(citations[i-1]>=citations.size()-i+1&&citations[i-1]>0){
                res=min(citations[i-1],(int)citations.size()-i+1);
                break;
            }
        }
        return res;
    }
};
