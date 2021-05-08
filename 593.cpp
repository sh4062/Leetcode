class Solution {
public:
    int dist(int x1,int y1,int x2,int y2){
        return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);

    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d1 = dist(p1[0],p1[1],p2[0],p2[1]);
        int d2 = dist(p1[0],p1[1],p3[0],p3[1]);
        int d3 = dist(p1[0],p1[1],p4[0],p4[1]);

        if(d1==d2){
            if(d3>d1&&dist(p3[0],p3[1],p2[0],p2[1])==d3){
                if(dist(p4[0],p4[1],p3[0],p3[1])==d1)
                return true;
            }

        }
        else if(d1==d3){
            if(d2>d1&&dist(p2[0],p2[1],p4[0],p4[1])==d2){
                if(dist(p3[0],p3[1],p2[0],p2[1])==d1)
                return true;
            }

        }else if(d2==d3){
            if(d1>d2&&dist(p4[0],p4[1],p3[0],p3[1])==d1){
                if(dist(p4[0],p4[1],p2[0],p2[1])==d2)
                return true;
            }

        }
        return false;

    }
};
