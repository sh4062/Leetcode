class Solution {
public:
vector<vector<int>>mp;
    int dfs(vector<vector<int>>&dungeon,int i,int j,int m,int n){
       if (i == m - 1 && j == n - 1) {
            return max(1 - dungeon[i][j], 1);
        }
        // 如果memo数组中有值，直接取出并返回，不进行后续的搜索。
        if (mp[i][j] > 0) {
            return mp[i][j];
        }
        // 同解法一，向右搜+向下搜
        int minRes = 0;
        if (i == m - 1) {
            minRes =  max(dfs(dungeon, i, j+1, m, n) - dungeon[i][j], 1);
        } else if (j == n - 1) {
            minRes = max(dfs(dungeon, i+1, j, m, n) - dungeon[i][j], 1);
        } else {
            minRes = max(min(dfs(dungeon, i+1, j, m, n), dfs(dungeon, i, j+1, m, n)) - dungeon[i][j], 1);
        }
        // 将结果存入memo数组
        return mp[i][j] = minRes;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int h = dungeon.size();
        int w = dungeon[0].size();
        mp.resize(h,vector<int>(w,0));
        return dfs(dungeon,0,0,h,w);
       

    }
};
