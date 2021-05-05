class Solution {
public:
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if(points.size()<3)return 0;
        int cnt = 0;
	for (int i=0; i<points.size(); ++i) 
	{
		unordered_map<double, int> ctr(points.size());
		for (int j=0; j<points.size(); ++j){
            cnt+=2*ctr[hypot(points[i][0] - points[j][0] , points[i][1] - points[j][1])];
			ctr[hypot(points[i][0] - points[j][0] , points[i][1] - points[j][1])]++;
            
        }
	}
        return cnt;

    }
};
