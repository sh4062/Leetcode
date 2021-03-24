class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>h=heights;
        sort(h.begin(),h.end());
        int res=0;
        for(int i = 0;i<h.size();i++){
            if(heights[i]!=h[i]){
                res++;
            }
        }
        return res;


    }
};
