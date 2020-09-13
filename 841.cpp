class Solution {
public:
    int max_=0;
    //map<int,int>m;
    map<int,int>mm;
    void dfs(int r,vector<vector<int>>& rooms,map<int,int>&mm){
       
        if(mm.count(r))return;
         mm[r]++;
        vector<int>v;
        for(auto i:rooms[r]){
            max_=max(max_,i);
            
            v.push_back(i);
             
        }
        
        for(auto j:v){
            //cout<<j;
            dfs(j,rooms,mm);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(rooms.size()<1)return true;
        //mm[0]++;
        dfs(0,rooms,mm);
        // cout<<max_;
        max_=rooms.size()-1;
        if(mm.size()-1==max_){
            return true;
            
        }else{
            return false;
            
        }
    }
};
