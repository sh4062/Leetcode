class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()<1)return 0; 
        if(citations.size()==1 && citations[0]==0)return  0;
        if(citations.size()==1 && citations[0]!=0)return  1;
        sort(citations.begin(),citations.end());
        if(citations[0]>=citations.size())return citations.size();
            for(int j = citations.size()-1;j>=1;j--){
                if(citations[citations.size()-j]>=j){
                    return j;
                }
                
           
        }
        return 0;
        
    }
};