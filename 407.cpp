class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
  int n = height.size(), m = height[0].size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(i == 0 || j == 0 || i == n-1 || j == m-1)
                {
                    que.push({height[i][j], i*m + j});
                    height[i][j] = -1;
                }
            }
        }

        int x[4] = {0, 0, 1, -1}, y[4] = {1, -1, 0, 0};

        int ans = 0, maxH = 0;
        while(!que.empty())
        {
            const auto& cur = que.top(); 
            
            int h = cur.first, i = cur.second/m, j = cur.second%m;
            que.pop();
            if(h > maxH) maxH = h;
            for(int k = 0; k < 4; ++k)
            {
                i += x[k], j += y[k];
                if(i >= 0 && i < n && j >= 0 && j < m && height[i][j] != -1)
                {
                    // cout<<height[i][j]<<":"<<i<<":"<<j<<endl;
                    que.push({height[i][j], i*m + j});
                    if(height[i][j] < maxH) ans += maxH - height[i][j];
                    height[i][j] = -1;
                }
                i -= x[k], j -= y[k];
            }
        }
        return ans;
    }


};
