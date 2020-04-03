class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> tmp;
        for(int i = 0;i<arr.size();i++){
        tmp[arr[i]]++;
        if(tmp[arr[i]]>arr.size()/4)return arr[i];
            }
        return 0;
    }
};