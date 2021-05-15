class Solution {
public:
    int res = -1;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    set<vector<vector<int>>>S;
    bool valid(vector<vector<int>>& b){
        for(int i = 0;i<3;i++){
            
            if(b[0][i]!=i+1)return false;
        }
        // cout<<b[1][2]<<endl;
        if(b[1][0]!=4)return false;
        if(b[1][1]!=5)return false;
        if(b[1][2]!=0)return false;
        return true;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        int x,y;
        for(int i=0;i<2;i++){
            for(int j = 0;j<3;j++){
                if(board[i][j]==0){
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        if(valid(board))
            return 0;
        S.insert(board);
        queue<vector<vector<int>>>q;
        q.push(board);
        int cnt = 1;
        while(!q.empty()){
            for(int j = q.size();j>0;j--){
            auto tmp=q.front();
            q.pop();
            for(int m=0;m<2;m++){
            for(int n = 0;n<3;n++){
                if(tmp[m][n]==0){
                    x=m;
                    y=n;
                    break;
                }
            }
        }
            //cout<<x<<":"<<y<<endl;
            
            for(int k = 0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx>=0&&xx<2&&yy>=0&&yy<3){
                
                swap(tmp[xx][yy],tmp[x][y]);
                if(valid(tmp)){
                // cout<<"?>"<<endl;
                return cnt;
                }
                if(!S.count(tmp)){
                q.push(tmp);
                }
                S.insert(tmp);
                swap(tmp[xx][yy],tmp[x][y]);
                
            }
        }
        
        }
        cnt++;
        }
        return res;

    }
};
