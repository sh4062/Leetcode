class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(k>n)return *max_element(arr.begin(),arr.end());
        if(k==1)return max(arr[0],arr[1]);
        int win = 1;
        int start = max(arr[0],arr[1]);
        for(int i = 2;i<arr.size();i++){
            if(start>arr[i]){
                win++;
                if(win==k)return start;
            }
            else{
                win=1;
                start=arr[i];
            }
        }
        return start;

    }
};
