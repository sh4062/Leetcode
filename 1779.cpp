class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<pair<int,int>>v;
        int maxv = INT_MAX;
        int index = -1;
        for(int i=0;i<points.size();i++){
            if(points[i][0]==x||points[i][1]==y){
                if(abs(points[i][0]-x)+abs(points[i][1]-y)<maxv){
                index = i;
                maxv=min(maxv,abs(points[i][0]-x)+abs(points[i][1]-y));
                }
            }
        }

        return index;

    }
};
