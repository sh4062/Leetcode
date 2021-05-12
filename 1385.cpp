class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for(const auto &i:arr1){
              int cnt1=0; 
             for(const auto &j:arr2){
                 if(abs(i-j)>d){
                     cnt1++;
                 }
             }
             if(cnt1==arr2.size())cnt++;
        }
        return cnt;

    }
};
