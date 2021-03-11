class Solution {
public:
    bool valid(int x,int y,int h,int w){
        if(x>=0&&x<h&&y>=0&&y<w){
            return true;
        }
        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res = matrix;
        queue<pair<int,int>>q;
        int h = matrix.size();
        int w = matrix[0].size();
        for(int i = 0;i<h;i++){
            for(int j = 0;j<w;j++){
                if(matrix[i][j]==0)
                {res[i][j]=0;
                 q.push({i,j});
                 }
            }
        }
        
        vector<vector<int>>  pos={{0,1},{1,0},{0,-1},{-1,0}};
        int step = 0;
        while(!q.empty()){
            step++;
            int qs = q.size();
            while(qs--){
                pair<int,int>cur = q.front();
                q.pop();
                for(int i = 0;i<4;i++){
                    int x = cur.first+pos[i][0];
                    int y = cur.second+pos[i][1];
                    if(valid(x,y,h,w)&&matrix[x][y]==1){
                        res[x][y]=step;
                        matrix[x][y]=0;
                        q.push({x,y});
                    }

                }
            }
        }
        return res;

    }
};
