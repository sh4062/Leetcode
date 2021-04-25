class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int>res;
        for(auto i:rectangles){
            res.push_back(min(i[0],i[1]));
        }
        int m = *max_element(res.begin(),res.end());
        int r=0;
        for(auto i:res){
            if(i==m)r++;
        }
        return r;

    }
};
