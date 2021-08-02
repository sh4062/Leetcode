class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX-100*10000);
        dist[src]=0;
        for(int i = 0;i<=k;i++){
            int flag = 0;
            vector<int>dist2(dist);
            
            for(auto &edge:flights){
                if(dist2[edge[1]]>dist[edge[0]]+edge[2]){
                    dist2[edge[1]]=dist[edge[0]]+edge[2];
                    //cout<<dist[edge[0]]+edge[2]<<endl;
                    flag=1;
                }
            }
            dist =dist2;
            if(flag==0)break;
        }
        // for(auto i:dist)cout<<i<<endl;;
        if(dist[dst]==INT_MAX-100*10000)return -1;
        return dist[dst];

    }
};
