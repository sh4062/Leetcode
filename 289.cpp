class Solution {
public:
   
    int h,w;
     bool valid(int x,int y){
         if(x>=0&&x<h&&y>=0&&y<w){
             return true;
         }
         return false;
     }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>b=board;
        h=board.size();
        w=board[0].size();
        for(int i = 0;i<h;i++){
            for(int j = 0;j<w;j++){
                if(board[i][j]==0){
                    int c = 0;
                    if(valid(i-1,j-1)){
                        if(board[i-1][j-1]==1)
                        c++;
                    }
                    if(valid(i-1,j)){
                        if(board[i-1][j]==1)
                        c++;
                    }
                    if(valid(i,j-1)){
                        if(board[i][j-1]==1)
                        c++;
                    }
                    if(valid(i+1,j)){
                        if(board[i+1][j]==1)
                        c++;
                    }
                    if(valid(i,j+1)){
                        if(board[i][j+1]==1)
                        c++;
                    }
                    if(valid(i+1,j+1)){
                        if(board[i+1][j+1]==1)
                        c++;
                    }
                    if(valid(i-1,j+1)){
                        if(board[i-1][j+1]==1)
                        c++;
                    }
                    if(valid(i+1,j-1)){
                        if(board[i+1][j-1]==1)
                        c++;
                    }
                    if(c==3){
                        b[i][j]=1;
                    }
                    
                }else{
                   
                    int c = 0;
                    if(valid(i-1,j-1)){
                        if(board[i-1][j-1]==1)
                        c++;
                    }
                    if(valid(i-1,j)){
                        if(board[i-1][j]==1)
                        c++;
                    }
                    if(valid(i,j-1)){
                        if(board[i][j-1]==1)
                        c++;
                    }
                    if(valid(i+1,j)){
                        if(board[i+1][j]==1)
                        c++;
                    }
                    if(valid(i,j+1)){
                        if(board[i][j+1]==1)
                        c++;
                    }
                    if(valid(i+1,j+1)){
                        if(board[i+1][j+1]==1)
                        c++;
                    }
                    if(valid(i-1,j+1)){
                        if(board[i-1][j+1]==1)
                        c++;
                    }
                    if(valid(i+1,j-1)){
                        if(board[i+1][j-1]==1)
                        c++;
                    }
                    if(c==3||c==2){
                        b[i][j]=1;
                    }else{
                        b[i][j]=0;
                    }
                }
            }
        }
        board=b;
    }
};
