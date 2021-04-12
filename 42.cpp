class Solution {
public:
    int trap(vector<int>& height) {
        int res= 0;
        vector<int>lm(height.size(),0);
        vector<int>rm(height.size(),0);
        for(int i = 1;i<height.size();i++){
            lm[i]=max(lm[i-1],height[i-1]);

        }
        for(int i = height.size()-2;i>=0;i--){
            rm[i]=max(rm[i+1],height[i+1]);
        }
        for(int i = 0;i<height.size();i++){
            int l = min(lm[i],rm[i]);
            res+=max(0,l-height[i]);

        }
        return res;

    }
};
