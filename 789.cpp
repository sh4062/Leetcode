class Solution {
public:
    int dist(int x1,int y1,int x2,int y2){
        return abs(x1-x2)+abs(y1-y2);
    }
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int>d;
        for(auto i:ghosts){
            d.push_back(dist(i[0],i[1],target[0],target[1]));
        }
        int dd=dist(0,0,target[0],target[1]);
        for(auto i:d){
            if(i<=dd)
            return false;
        }
        return true;


    }
};
