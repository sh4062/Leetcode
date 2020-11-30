class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0)return true;
        int n = numCourses;
        unordered_map<int,set<int>>g;
        unordered_map<int,set<int>>indeg;
        set<int>c;
        for(auto i :prerequisites){
            g[i[0]].insert(i[1]);
            indeg[i[1]].insert(i[0]);
            c.insert(i[0]);
            c.insert(i[1]);
        }
        set<int>res;
        int flag = 0;
        // while(flag){
        //     cout<<res.size();
        for(int i = 0;i<n;i++){
            if(g.find(i)==g.end()){
                flag = 1;
                res.insert(i);
            }
        }
        if(flag==0)return false;
        
        for(int i = 0;i<n;i++){
            int pre = res.size();
            
            for(auto  j:res){
                
                for(auto k:indeg[j]){
                    if(g[k].count(j))
                    g[k].erase(j);
                    if(g[k].size()==0){
                        res.insert(k);
                    }
                }
                
                
            
        }if(res.size()==pre)break;
            }
           // }

        //cout<<res.size();
        return res.size()==n;
    }
};
