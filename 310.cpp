class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return { 0 };
        vector<int>de(n,0);
        vector<vector<int>>G(n);
        for(auto i:edges){
            G[i[0]].push_back(i[1]);
            G[i[1]].push_back(i[0]);
            de[i[0]]++;
            de[i[1]]++;
        }

        queue<int>q;
        for(int i = 0;i<de.size();i++){
            if(de[i]==1){
                q.push(i);
            }
        }
        vector<int>res;
        while(!q.empty()){
            int sz = q.size();
            res.clear();
            while(sz--){
                auto tmp = q.front();
                res.push_back(tmp);
                q.pop();
                for(auto j: G[tmp]){
                    de[j]--;
                    if(de[j]==1){
                        q.push(j);
                    }
                }

            }

        }
        return res;

    }
};
