class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp [111][111]={0};
        dp[0][0]=1;
        int h = obstacleGrid.size();
        int w = obstacleGrid[0].size();
        if(h==1&&w==1)return obstacleGrid[0][0]==0?1:0;
        if(h==1){
            for(auto i:obstacleGrid[0]){
                if(i==1)return 0;
            }
            return 1;
        }
        if(w==1){
            for(auto i:obstacleGrid){
                if(i[0]==1)return 0;
            }
            return 1;
        }
       // cout<<h;
        if(obstacleGrid[h-1][w-1]==1)return 0;
        if(obstacleGrid[0][0]==1)return 0;
        if(obstacleGrid[0][1]==0)dp[0][1]=1;else{dp[0][1]=0;}
        if(obstacleGrid[1][0]==0)dp[1][0]=1;else{dp[1][0]=0;}
        for(int i =0;i<h;i++){
            for(int j = 0;j<w;j++){
                if(i>=1&&j>=1&&obstacleGrid[i][j]!=1){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }else if(i==0&&j>=1&&obstacleGrid[i][j]!=1){
                    dp[i][j] = dp[i][j-1];
                }else if(j==0&&i>=1&&obstacleGrid[i][j]!=1){
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        //cout<<dp[1][0];
        return dp[h-1][w-1];
    }
};
