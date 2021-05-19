class Solution {
public:
    int dx[8]={1,-1,0,0,1,-1,-1,1};
    int dy[8]={0,0,1,-1,1,-1,1,-1};
    void dfs(vector<vector<char>>& b,int x,int y){
        
        if(b[x][y]!='E'){
            return;
        }
        int mines =0;
        for(int k=0;k<8;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];

            if(xx>=0&&xx<b.size()&&yy>=0&&yy<b[0].size()&&b[xx][yy]=='M')
            {
                mines++;
            }

        }
        if(mines==0){
            b[x][y]='B';
            for(int k=0;k<8;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx>=0&&xx<b.size()&&yy>=0&&yy<b[0].size()){
               
                dfs(b,xx,yy);

            }
            }

        }
        else{
            b[x][y]='0'+mines;
        }
        return ;


    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0],y=click[1];
        if(board[x][y]=='M'){
            board[x][y]='X';

        }else{
           dfs(board,x,y);
        }
        return board;

    }
};
