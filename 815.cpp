class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        queue<int>q;
        q.push(source);
        unordered_map<int,vector<int>>mp;
        int cnt = 1;
        int sz = routes.size();
        vector<int>vis(sz,0);
        for(int i = 0;i<sz;i++){
            for(auto j:routes[i]){
                mp[j].push_back(i);
            }
        }
        while(!q.empty()){
            for(int i = q.size();i>0;i--){
            auto tmp = q.front();
            q.pop();
            for(auto j:mp[tmp]){
                if(!vis[j]){
                    vis[j]=1;
                    for(auto k:routes[j]){
                        if(k==target)return cnt;
                        q.push(k);
                    }
                    
                }
            }

            }
            cnt++;

        }
        return -1;
    }
};
