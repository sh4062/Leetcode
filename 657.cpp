class Solution {
public:
    bool judgeCircle(string moves) {
        int x =0;
        int y = 0;
        for(auto i:moves){
            if(i=='R'){
                x++;

            }
            if(i=='L'){
                x--;
                
            }
            if(i=='U'){
                y++;
                
            }
            if(i=='D'){
                y--;
            }
        }
        return x==0&&y==0;

    }
};
