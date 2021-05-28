class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] =  {0,0,1,-1};
    int encode(const vector<vector<int>>& mat){
        int x = 0;
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                x = x * 2 + mat[i][j];
            }
        }
        return x;
    }
    vector<vector<int>> decode(int x,int m,int n){
        vector<vector<int>> mat(m, vector<int>(n));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                mat[i][j] = x & 1;
                x >>= 1;
            }
        }
        return mat;
    }
    void convert(vector<vector<int>>& mat,int x,int y){
        for(int k = 0;k<4;k++){
            int xx = x+dx[k];
            int yy=y+dy[k];
            if(xx>=0&&xx<mat.size()&&yy>=0&&yy<mat[0].size()){
                mat[xx][yy]^=1;
            }
        }
         mat[x][y]^=1;
    }
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int res = 0;
        queue<int>q;
        int cur = encode(mat);
        if(cur==0)return 0;
        unordered_set<int>vis;
        vis.insert(cur);
        q.push(cur);
        int step=1;
        while(!q.empty()){
            for(int i = q.size();i>0;i--){
                auto tmp = decode(q.front(),m,n);
                q.pop();
                for(int xx = 0;xx<m;xx++){
                    for(int yy=0;yy<n;yy++){
                        convert(tmp,xx,yy);
                        int c = encode(tmp);
                        
                        if(c==0)
                            return step;
                        
                        if(!vis.count(c)){
                            vis.insert(c);
                            q.push(c);
                        }
                        convert(tmp,xx,yy);
                    }

                }


            }
            step++;

        }
        return -1;

    }
};
