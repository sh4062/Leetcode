long long E=int(pow(10,9)+7);
class Solution {
public:
    int al;
    vector<vector<int>>memo;
    int dfs(int curp,int step){
        if(step<0)return 0;
        if(curp<0||curp>=al)return 0;
        if(memo[curp][step]!=-1)return memo[curp][step];
        if(step==0&&curp==0){
            {
                return 1;
            }
            
        }
        long long A = 0,B=0,C=0;
        A=dfs(curp+1,step-1);
        B=dfs(curp,step-1);
        C=dfs(curp-1,step-1);
        memo[curp][step]=(A+B+C)%E;
        return memo[curp][step];


    }
    int numWays(int steps, int arrLen) {
        al=arrLen;
        memo.resize(steps+1,vector<int>(steps+1,-1));
        int ret=dfs(0,steps);
        return ret;

    }
};
