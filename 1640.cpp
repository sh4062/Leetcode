class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int>mp;
        for(int i = 0;i<pieces.size();i++){
            mp[pieces[i][0]]=i;
        }
        for(int i = 0;i<arr.size();){
            cout<<arr[i]<<"!"<<endl;
            if(mp.find(arr[i])!=mp.end()){
                int k = pieces[mp[arr[i]]].size();
                int ii = i;
                int j = 0;
                for(j;j<k;j++,i++){
                    if(pieces[mp[arr[ii]]][j]==arr[i]){
                        cout<<pieces[mp[arr[ii]]][j]<<endl;
                        
                        //j++;

                    }else {
                        // cout<<pieces[mp[arr[ii]]][j]<<endl;
                        // cout<<arr[i]<<endl;
                    
                    return false;}
                }
                if(j!=k){cout<<k<<endl;return false;}
                if(i==arr.size())return true;



            }else{
                //cout<<arr[i];
                return false;
            }
        }
        return true;

    }
};
