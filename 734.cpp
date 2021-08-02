class Solution {
public:
    int flag = 0;
    int tt = 0;
    vector<int>dist;
    vector<unordered_map<int, int>> mp;
    void dfs(vector<vector<int>>&G,int cur,int t){
        
        if(dist[cur]>t){
            dist[cur]=t;
            //cout<<dist[4]<<endl;
        for(int i = 1;i<G.size();i++){
            if(G[cur][i]>=0){
                dfs(G,i,t+G[cur][i]);
            }
        }
        }
    }
    void dfs2(int i, int t) {
        if (dist[i] > t) {
           dist[i] = t;
            for (auto& cur : mp[i]) {
                dfs2(cur.first, cur.second + t);
            }
        }
    }


    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>>G;
        dist.resize(n+1,INT_MAX);
        G.resize(n+1,vector<int>(n+1,-1));
        for(auto i:times){
            G[i[0]][i[1]]=i[2];
            //cout<<G[i[0]][i[1]]<<endl;
        }

        // 建图 - 邻接表
        mp.resize(n + 1);
        for (auto& edg : times) {
            mp[edg[0]][edg[1]] = edg[2];
        }


        dist[0]=0;
        dist[k]=INT_MAX;
        // cout<<G[5][4];
        dfs(G,k,0);
        //dfs2(k,0);
        dist[k]=0;
        for(auto i:dist){
            //cout<<i<<endl;
            if(i==INT_MAX)return -1;
            tt=max(tt,i);
        }
        return tt;

    }
};
