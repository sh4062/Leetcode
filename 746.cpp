class Solution {
public:
    unordered_map<int,int>memo;
    int dfs(int s,vector<int>& cost){
        if(s<0)return INT_MAX;
        if (s == 0 || s == 1)
            return cost[s];
        if(memo[s]){
            return memo[s];
        }
        int res = cost[s]+min(
        dfs(s-1,cost),
        dfs(s-2,cost));
        memo[s]=res;
        return res; 
       

    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(
        dfs(cost.size()-1,cost),
        dfs(cost.size()-2,cost));
        

    }
};
