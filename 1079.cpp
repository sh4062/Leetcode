class Solution {
public:
    set<string>S;
    int cnt = -1;
    string tmp;
    vector<int>vis;
    void dfs(string s){
        if(!S.count(tmp)){
                cnt++;
                //cout<<tmp<<endl;
                S.insert(tmp);
        }
        // if(index >=s.size()){
        //     return;
        // }
        for(int i = 0;i<s.size();i++){
            if(vis[i])continue;
            vis[i]=1;
            tmp+=s[i];
            dfs(s);
            tmp.pop_back();
            vis[i]=0;
        }
    }
    int numTilePossibilities(string tiles) {
        vis.resize(tiles.size(),0);
        dfs(tiles);
        return cnt;

    }
};
