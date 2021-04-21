class Solution {
public:
    unordered_set<int> D;
    vector<int>c;
    vector<int>memo;
    //我们用 \textit{dp}(i)dp(i) 来表示从第 ii 天开始到一年的结束，我们需要花的钱。考虑到一张通行证可以让我们在「接下来」的若干天进行旅行，所以我们「从后往前」倒着进行动态规划。
    int dfs(int d){
        if(d>365)return 0;
        if(memo[d]!=-1){
            return memo[d];
        }
        if(D.find(d)==D.end()){
            memo[d]=dfs(d+1);
        }else{
            memo[d]=min({dfs(d+1)+c[0],dfs(d+7)+c[1],dfs(d+30)+c[2]});

        }
        return memo[d];

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        c=costs;
        memo.resize(366,-1);
        for(auto i:days){
            D.insert(i);
        }
        int res =dfs(1);
        return res;

    }
};
