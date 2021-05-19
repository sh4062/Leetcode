class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int m = img1.size();
        int n = img1[0].size();
        int res = 0;
        for(int x = -m;x<m;x++)
        for(int y=-n;y<n;y++){
        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(x+i>=0&&x+i<m&&y+j<n&&y+j>=0)
                if(img1[x+i][y+j]==1&&img2[i][j]==1){
                    cnt++;
                }

            }
        }
        res=max(res,cnt);
        }
        return res;

    }
};
