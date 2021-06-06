class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        int sz = arr2.size();
        for(int i=0;i<arr2.size();i++)mp[arr2[i]]=i;
        for(auto i:arr1){
            if(mp.count(i)==0){
                arr2.push_back(i);
            }
        }
        sort(arr2.begin()+sz,arr2.end());
        for(int i = sz;i<arr2.size();i++){
            mp[arr2[i]]=i;
        }
        sort(arr1.begin(),arr1.end(),[&](int a,int b){if(mp.count(a)&&mp.count(b)){
            return mp[a]<mp[b];
        }else {return a<b;}});
        return arr1;

    }
};
