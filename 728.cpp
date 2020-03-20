class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left;i<=right;i++){
            if(i<10){res.push_back(i);}
            else{
                int ii = i;
                int c = 1;
                while(ii/10!=0){
                    ii=ii/10;
                    c++;
                }
                ii=i;
                //cout<<c;
                if(ii%10==0){ goto part2;}
                while(c--){
                    if(ii%10==0){ goto part2;}
                    if(i%(ii%10)!=0){
                        goto part2;
                        
                    }
                    ii = ii/10;
                    //if(i>100&&ii%10==0){ goto part2;}
                    //cout<<ii;
                    
                }
                res.push_back(i);   
                }
part2:; 
            }
        return res;
        }
    
};