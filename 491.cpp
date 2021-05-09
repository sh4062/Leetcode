class Solution {
public:
    set<vector<int>> S;
    vector<int>tmp;
    vector<int>n;
    void dfs(int index){
        if(index>n.size())return;
        if(tmp.size()>=2)
        S.insert(tmp);
        for(int i = index;i<n.size();i++){
            if(tmp.size()==0){
                tmp.push_back(n[i]);
                dfs(i+1);
                tmp.pop_back();
            }else if(n[i]>=tmp.back()){
                tmp.push_back(n[i]);
                dfs(i+1);
                tmp.pop_back();
            }
        }


    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums;
        dfs(0);
        vector<vector<int>>res (S.begin(),S.end());
        return res;

    }
};
