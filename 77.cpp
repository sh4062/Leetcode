class Solution {
public:
    int kk=0;
    int nn =0;
    int c =0;
    vector<int> v;
    vector<int> tmp;
    vector<vector<int>>res;
    void dfs(int n){
        if(tmp.size()==kk){
            res.push_back(tmp);
            return;
        }
        for(int i =n+1;i<=nn;i++){
            tmp.push_back(v[i]);
            dfs(i);
            tmp.pop_back();
            
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        kk=k;
        nn = n;
        v.push_back(0);
        for(int i =1;i<=n;i++){
            v.push_back(i);
        }
        dfs(0);
       // cout<<c;
        return res;
    }
};
