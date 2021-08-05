class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>indegree;
        indegree.resize(n,0);
        unordered_map<int,vector<int>>G;
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()>0){
                for(auto j:graph[i]){
                    indegree[i]++;
                    G[j].push_back(i);
                }

            
            }

        }
        vector<int>res;
        queue<int>q;
        for(int i = 0;i<indegree.size();i++){
            if(indegree[i]==0){
                
                q.push(i);
                res.push_back(i);
            }
        }
        //cout<< indegree[5]<<endl;
        while(!q.empty()){

            auto tmp = q.front();
           
            q.pop();
            for(auto i:G[tmp]){
                 
                indegree[i]--;
                if(indegree[i]==0){
                      res.push_back(i);
                
                    q.push(i);
                }
            }

        }
        sort(res.begin(),res.end());
        return res;

    }
};
