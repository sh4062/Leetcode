class Solution {
public:
    int cnt = 0;
    int flag = 0;
    vector<int>tmp;
    vector<int>res;
    bool valid(vector<int>& arr){
        if(arr.size()<2)return true;
        for(int i = 1;i<arr.size();i++){
            if(arr[i]<arr[i-1])return false;
        }
        return true;
    }
    // bool dfs(vector<int>& a,int times){
    //     if(flag)return false;
    //     if(times>a.size())return false;
    //     if(valid(a)){
    //         res=tmp;
    //         flag = 1;
    //         cnt=times;
    //         return true;
    //     }
    //     if(flag==0)
    //     for(int i = 1;i<=a.size();i++){
    //         reverse(a.begin(),a.begin()+i);
    //         tmp.push_back(i);
    //         if(dfs(a,times+1))return true;
    //         reverse(a.begin(),a.begin()+i);
    //         tmp.pop_back();
    //     }
    //     return false;

    // }
    vector<int> pancakeSort(vector<int>& arr) {
        if(valid(arr))return res;
        //dfs(arr,0);
        //cout<<cnt;
        int n = arr.size()-1;
        while(n>0){
                if(arr[n]!=n+1){
                int low = find(arr.begin(), arr.end(), n+1) - arr.begin();
                //cout<<low<<endl;
                reverse(arr.begin(),arr.begin()+low+1);
                res.push_back(low+1);
                reverse(arr.begin(),arr.begin()+n+1);
                res.push_back(n+1);
                //for(auto i:arr)coures.push_back();
            }
            //cout<<n<<endl;
            n--;
            
        }

        return res;
        

    }
};
