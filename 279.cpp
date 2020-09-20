class Solution {
public:
    int flag = 0;
    int res=INT_MAX;
    unordered_map<int,int>memo;
    void dfs(int a,int &n,vector<int>&v,int p){
        
        
        if(p>res)return;
        if(memo.find(a)!=memo.end()){
            //if(a==5)cout<<memo[5];
            res=min(res,p+memo[a]);
            return;
        }
        //if(flag==1)return;
        if(a<0)return;
        if(a==0){
            
            res=min(res,p);
            //flag=1;
            return;
        }
        for(int i = v.size()-1;i>=0&&v[i]>=(n-a);i--){
            
            // if((a)%v[i]==0){
            //     memo[a]=p+(a)/v[i];
            //      res=min(res,p+(a)/v[i]);
            //      //flag=1;
            //      return;
            // }
            if(a-v[i]<0)continue;
            //cout<<a-v[i]<<endl;
            memo[a]=p;
            dfs(a-v[i],n,v,p+1);
        }
    }
    int numSquares(int n) {
        //if(n==23)return 4;
        int q = sqrt(n);
        vector<int>v;
        for(int i = 1;i<=q;i++){
            v.push_back(i*i);
            memo[i*i]=1;
        }
        dfs(n,n,v,1);
        return res-1;
    }
};
