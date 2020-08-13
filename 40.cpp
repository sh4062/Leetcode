class Solution {
public:
    int c =0;
    int t=0;
    deque<int> can;
    vector<int> tmp;
    set<vector<int>> res;
    vector<vector<int>> ress;
    void dfs(int i){
        if(c>t){
            return;
        }
        if(c==t){
            res.insert(tmp);
            return;
        }
        for(int j =i+1 ;j<can.size();j++){
            tmp.push_back(can[j]);
            c+=can[j];
            dfs(j);
            tmp.pop_back();
            c-=can[j];
            
        }
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        can.assign(candidates.begin(),candidates.end());
        sort(can.begin(),can.end());
        can.push_front(0);
        t=target;
        dfs(0);
        ress.assign(res.begin(),res.end());
        return ress;
    }
};
