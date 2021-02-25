class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int h = board.size();
        int w = board[0].size();
        queue<pair<int,int>> q;
        vector<pair<int,int>> aux;
        for(int i = 0;i<h;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
            }
            if(board[i][w-1]=='O'){
                q.push({i,w-1});
            }
        }
        for(int i = 0;i<w;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
            }
            if(board[h-1][i]=='O'){
                q.push({h-1,i});
            }
        }
        while(!q.empty()){
            aux.push_back(q.front());
            board[aux.back().first][aux.back().second]='-';
            //cout<<aux.back().first<<" "<<aux.back().second<<endl;
            q.pop();
            if(aux.back().first-1>=0&&board[aux.back().first-1][aux.back().second]=='O'){
                q.push({aux.back().first-1,aux.back().second});

            }
            if(aux.back().first+1<h&&board[aux.back().first+1][aux.back().second]=='O'){
                q.push({aux.back().first+1,aux.back().second});

            }
            if(aux.back().second-1>=0&&board[aux.back().first][aux.back().second-1]=='O'){
                q.push({aux.back().first,aux.back().second-1});

            }
            if(aux.back().second+1<w&&board[aux.back().first][aux.back().second+1]=='O'){
                q.push({aux.back().first,aux.back().second+1});

            }


        }
 
        for(int i = 0;i<h;i++){
            for(int j = 0;j<w;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='-'){
                    board[i][j]='O';
                }
            }
        }

    }
};
