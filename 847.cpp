#include<bitset>
const int num = 31;
class Solution {

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<pair<int,int>>q;
        unordered_map<string,bool>vis;
        int target = 0;
        for(int i = 0; i < graph.size(); i++){
            int path = 1 << i;
            target |= path;
            //
            q.push(make_pair(path, i));
            vis[to_string(path) + "-" + to_string(i)] = true;
        }
        
        int res = 0;
        while(!q.empty()){
            int qs = q.size();
            for(int i = 0;i<qs;i++){
            auto tmp = q.front();q.pop();
            //cout<<(bitset<num>)tmp.first<<endl;
            if(tmp.first==target)return res;
            for(int next:graph[tmp.second]){
                int next_state = tmp.first| (1 << next);
                string s =to_string(next_state) +"-"+to_string(next);
                if(vis[s])continue;
                vis[s]=true;
                q.push({next_state,next}); 
            }


            }
            res++;
        }



        return -1;


    }
};
