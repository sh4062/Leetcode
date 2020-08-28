class Solution {
public:
    vector<int>t;
    vector<vector<int>> res;
    int m,kk;
    void dfs(int s,int k,int a){
       // cout<<a;
        if(s>9){
            return;
        }
        if(k>kk){
            return;
        }
        if(a==m &&k==kk){
            res.push_back(t);
            return;
        }
        for(int i=s+1;i<=9;i++){
            t.push_back(i);
            dfs(i,k+1,a+i);
            t.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        m=n;
        kk=k;
        for(int i=0;i<k;i++){
            
        }
        dfs(0,0,0);
        return res;
    }
};
