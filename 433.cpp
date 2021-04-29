class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int res = 0;
        queue<string>q;
        q.push(start);
        unordered_map<string,int> vis;
        while(!q.empty()){
            res++;
            int s = q.size();
            for(int i = 0;i<q.size();i++){
                string tmp = q.front();
                q.pop();
                for(auto b:bank){
                    int mismatch = 0;
                    for(int i = 0;i<b.size();i++){
                        if(b[i]!=tmp[i])mismatch++;
                        if(mismatch>1)break;
                    }
                    if(mismatch==1){
                        if(!vis.count(b)){
                            q.push(b);
                            vis[b]++;
                        }
                        if(b==end)
                        return res;

                    }
                }

            }
        }
        return -1;

    }
};
