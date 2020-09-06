class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()<1)return res;
        //res.push_back(matrix[0][0]);
        int f = 1;
        int x =0;
        int y =0;
        int count=0;
        int h=matrix.size();
        int w=matrix[0].size();
        while(count!=h*w){
            
        if(f<0){
            while(x<=h-1&&y>=0){
                res.push_back(matrix[x][y]);
                x++;
                y--;
                count++;
                cout<<res.size();
            }
            x--;
            y++;
            if(x==h-1){
                y++;
                f*=-1;
                continue;
            }
            else if(y==0){
                x++;
                f*=-1;
                continue;
                
            }
        }else{
             while(x>=0&&y<=w-1){
                res.push_back(matrix[x][y]);
                x--;
                y++;
                count++;
            }
            x++;
            y--;
             if(y==w-1){
                x++;
                f*=-1;
                continue;
                
            }
           
            else
             if(x==0){
                y++;
                f*=-1;
                continue;
            }
            
        }
            
            }
        return res;
    }
};
