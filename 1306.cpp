class Solution {
public:
    set<int> m0;
    bool dfs(int cur,vector<int>& a,int left){
        if(cur<0||cur>=a.size()||left==0){
            return false;
        }
        if(m0.count(cur))return true;
        bool ret = false;
       
        return  dfs(cur+a[cur],a,left-1)||
        dfs(cur-a[cur],a,left-1);

    }
    bool canReach(vector<int>& arr, int start) {
        
        for(int i = 0;i<arr.size();i++){
            if(arr[i]==0){
                m0.insert(i);
            }
        }
        return dfs(start,arr,arr.size());

    }
};
