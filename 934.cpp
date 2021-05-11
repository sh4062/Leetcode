class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        queue<int>q;
        int m = A.size();
        int n = A[0].size();
        int f = 1;
        for(int i= 0;i<m;i++)
            for(int j = 0;j<n;j++){
                if(f!=0&&A[i][j]==1){
                    q.push(i*n+j);
                    A[i][j]=2;
                    f=0;
                }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            int x = tmp/n;
            int y =tmp%n;
            for(int k =0;k<4;k++){
                int xx = x+dx[k];
                int yy=y+dy[k];
                if(xx>=0&&xx<m&&yy>=0&&yy<m&&A[xx][yy]==1){
                    A[xx][yy]=2;
                    q.push(xx*n+yy);
                }
            }

        }
        queue<int>q2;
        for(int i= 0;i<m;i++)
            for(int j = 0;j<n;j++){
                if(A[i][j]==2){
                    q2.push(i*n+j);
                    
                }
        }
        int ret = 0;
        while(!q2.empty()){
            for(int i = q2.size();i>0;i--){
            auto tmp = q2.front();
            q2.pop();
            int x = tmp/n;
            int y =tmp%n;
            for(int k =0;k<4;k++){
                int xx = x+dx[k];
                int yy=y+dy[k];
                if(xx>=0&&xx<m&&yy>=0&&yy<m&&A[xx][yy]!=2){
                    if(A[xx][yy]==1)return ret;
                    A[xx][yy]=2;
                    q2.push(xx*n+yy);
                }
            }

        }
        ret++;
        }
        
        
        
        return 1;

    }
};
