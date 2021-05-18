class Solution {
public:
    int cnt = 0;
    int countArrangement(int n) {
        vector<int>v(n,0);
        for(int i = 1;i<=n;i++){
            v[i-1]=i;
        }
        dfs(0,v);
        return cnt;

    }
    void dfs(int n,vector<int>&v){
        if(n>=v.size()){
            cnt++;
            return;
        }
        for(int i = n;i<v.size();i++){
            swap(v[i],v[n]);
            if(v[n] % (n+1) == 0 || (n+1) % v[n] == 0)
                dfs(n+1,v);
            swap(v[n],v[i]);
        }

    }
};
