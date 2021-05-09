class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dir = 0;
        int res = 0;
        int x = 0;
        int y = 0;
        map<pair<int,int>,int>mp;
        for(auto i:obstacles){
            mp[{i[0],i[1]}]++;
        }
        for(auto i:commands){
            if(i==-1){
                dir+=1;
                dir=(dir+4)%4;

            }else if(i==-2){
                dir-=1;
                dir=(dir+4)%4;
            }else{
                if(dir==0){
                    while(i){
                        i--;
                        y++;
                        if(mp[{x,y}]){
                            y--;
                            break;
                        }
                        
                    }
                    
                }else if(dir==1){
                     while(i){
                        i--;
                        x++;
                        if(mp[{x,y}]){
                            x--;
                            break;
                        }
                        
                    }

                }else if(dir==2){
                     while(i){
                        i--;
                        y--;
                        if(mp[{x,y}]){
                            y++;
                            break;
                        }
                        
                    }
                    
                }else if(dir==3){
                     while(i){
                        i--;
                        x--;
                        if(mp[{x,y}]){
                         {
                            x++;
                            break;
                        }
                        }
                    }
                    
                }
                //cout<<x<<":"<<y<<endl;
                res=max(res,x*x+y*y);

            }
        }
        return res;
        

    }
};
