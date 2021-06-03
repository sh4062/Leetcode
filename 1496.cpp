class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>>mp;
        mp.insert({0,0});
        int x=0,y=0;
        for(auto i:path){
            
            if(i=='N'){
                y++;

            }
            if(i=='S'){
                y--;
                
            }
            if(i=='E'){
                x--;
                
            }
            if(i=='W'){
                x++;
                
            }
            if(mp.find({x,y})!=mp.end())return true;
            mp.insert({x,y});
        }
        return false;

    }
};
