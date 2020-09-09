class Solution {
public:
    int res=0;
    int m,n;
    vector<vector<int>>M;
    vector<vector<int>>memo;
    bool valid(int x,int y){
        if(x>=0&&x<=m-1&&y>=0&&y<=n-1){
            return true;
        }
        return false;
    }
    int dfs(int x,int y,int sum){
        int u=0,d=0,l=0,r=0;
        //sum+=1;
        
       
        if(memo[x][y]!=0){
            return memo[x][y];
        }
        //memo[x][y]++;
        if(valid(x-1,y)&&M[x][y]>M[x-1][y]){
            u=dfs(x-1,y,sum);
        } 
            if(valid(x+1,y)&&M[x][y]>M[x+1][y]){
               d= dfs(x+1,y,sum);
        }
                if(valid(x,y-1)&&M[x][y]>M[x][y-1]){
          l=   dfs(x,y-1,sum);
        }
                    if(valid(x,y+1)&&M[x][y]>M[x][y+1]){
                  r=      dfs(x,y+1,sum);
        }{
                        int maxV=max(sum,max(u,max(d,max(l,r))));
                        memo[x][y]=maxV+1;
                         if(maxV+1>res){
                             res=maxV+1;
            }
                        return maxV+1;
        }
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        if(m<1)return 0;
        n=matrix[0].size();
        M=matrix;
        memo.resize(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                dfs(i,j,0);
            }
        }
        return res;
    }
    
};
