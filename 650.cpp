class Solution {
public:
    int res=1;
    int ress=INT_MAX;
    void dfs(int a,int aa,int n){
        //cout<<a;
        if(a>n){
            return;
        }
        if(aa>n){
            return;
        }
        if(aa==n){
            ress=min(ress,res);
            
            //cout<<res<<" "<<ress;
            return;
        }
        if(a!=aa){
        res++;
        dfs(aa,aa,n);
        res--;
            }
        res++;
        dfs(a,aa+a,n);
        res--;
        
    }
    int minSteps(int n) {
        if(n==1)return 0;
        dfs(1,1,n);
        return ress;
    }
};
