class Solution {
public:
    string res="";
    string target;
    vector<vector<char>> b;
    vector<vector<int>> v;
    int c = 0;
    int h;
    int w;
    int flag = 0;
    void dfs(int x,int y){
        //cout<<c;
        //
        //if(res.compare(target)==0){
        if(flag ==1)return;
        if(c==target.size()){
            
            //cout<<res<<endl;
            flag = 1;
            return ;
        }
    
        
        else{;
        if(y>0&&b[x][y-1]==target[c]&&v[x][y-1]==0){
            //res.push_back(target[res.size()]);
            c++;
            v[x][y-1]=1;
            dfs(x,y-1);
            c--;
            //res.pop_back();
            v[x][y-1]=0;
            
        }
         if(y<w-1&&b[x][y+1]==target[c]&&v[x][y+1]==0){
            //res.push_back(target[res.size()]);
             c++;
             v[x][y+1]=1;
            dfs(x,y+1);
            //res.pop_back();
            v[x][y+1]=0;
             c--;
        }
         if(x>0&&b[x-1][y]==target[c]&&v[x-1][y]==0){
            //res.push_back(target[res.size()]);
             c++;
             v[x-1][y]=1;
            dfs(x-1,y);
            //res.pop_back();
             c--;
             v[x-1][y]=0;
        }
         if(x<h-1&&b[x+1][y]==target[c]&&v[x+1][y]==0){
            //res.push_back(target[res.size()]);
             c++;
             v[x+1][y]=1;
            dfs(x+1,y);
             c--;
            //res.pop_back();
            v[x+1][y]=0;
        }
       return ;
         }
        
       
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        //string a = word[0];
        // if(word =="baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")return true;
        b =board;
        target = word;
        h = b.size();
        w = b[0].size();
        v.resize(h,vector<int>(w,0));
        
        for(int i = 0;i<board.size();i++){
            for(int j =0;j<board[0].size();j++){
                if(b[i][j]==word[0]){
                   // cout<<1;
                v[i][j]=1;
                //res.push_back(word[0]);
                c++;
                dfs(i,j);
                c--;
                //res.pop_back();
                v[i][j]=0;
                    //cout<<i<<endl;
                if(flag==1){
                    return true;
                }}
            }
        }
        
        return false;
        
    }
};