class Solution {
public:
    vector<int>a;
    int memo[1005];
    int dfs(int cur,int d){

        if(memo[cur]!=-1)return memo[cur];
        int ret = 0;
        for(int i = 1;i<=d;i++){
            if(cur+i<a.size()&&a[cur+i]<a[cur])
            ret=max(ret,dfs(cur+i,d));
            else break;
        }
        for(int i = 1;i<=d;i++){
            if(cur-i>=0&&a[cur-i]<a[cur])
            ret=max(ret,dfs(cur-i,d));
            else break;
        }
        return memo[cur]=ret+1;
    }
    int maxJumps(vector<int>& arr, int d) {
        a=arr;
        int res = 0;
        memset(memo,-1,sizeof(memo));
        for(int i = 0;i<a.size();i++){
            
            res=max(res,dfs(i,d));
        }
        // memset(memo,-1,sizeof(memo));
        // res=max(res,dfs(10,d));
        return res;

    }
};
