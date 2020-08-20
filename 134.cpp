class Solution {
public:
    int flag =0;
    vector<int> g, c;
    int cg=0;
    void dfs(int s,int a){
        //cout<<a;
        if(a==g.size()){
            flag=1;
            return ;
        }
    int current=(s+a)%g.size();
    int next=(s+a+1)%g.size();
       if(cg-c[current]<0)return;
       cg = cg-c[current]+g[next];
        //cout<<current<<" "<<cg<<endl;
    if(cg>=0){
        // cout<<a<<endl;
        dfs(s,a+1);
    }else{
        return;
    }
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        g=gas;
        c=cost;
        for(int i=0;i<gas.size();i++){
        cg=gas[i];
        dfs(i,0);
        if(flag==1)return i;
        }
        return -1;
    }
};
