class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int index = 0;
        int cnt = 0;
        int cut_max =0;
        for(int i =0;i<arr.size();i++){
            cut_max=max(arr[i],cut_max);
            if(i==cut_max){
               cnt++;
            }
            
            

        }
        //cout<<cnt;
        return cnt;

    }
};
