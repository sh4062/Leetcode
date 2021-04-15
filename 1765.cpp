class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>>q;
        vector<vector<int>>res=isWater;
        for(int i = 0;i<isWater.size();i++){
            for(int j = 0;j<isWater[0].size();j++){
                   if(isWater[i][j]==1){
                       q.push({i,j});
                   }
            }
        }
        int circle = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0;i<s;i++){
                int x = q.front().first;
                int y = q.front().second;
                res[x][y]=circle;
                q.pop();
                if(x-1>=0&&isWater[x-1][y]==0){
                    q.push({x-1,y});
                    isWater[x-1][y]=1;

                }
                if(x+1<isWater.size()&&isWater[x+1][y]==0){
                    q.push({x+1,y});
                    isWater[x+1][y]=1;

                }
                if(y-1>=0&&isWater[x][y-1]==0){
                    q.push({x,y-1});
                    isWater[x][y-1]=1;

                }
                if(y+1<isWater[0].size()&&isWater[x][y+1]==0){
                    q.push({x,y+1});
                    isWater[x][y+1]=1;

                }


            }

            circle++;
        }
        return res;

    }
};
