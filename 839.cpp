class Solution {
public: 
    vector<int> uf;
    int valid(string a,string b){
        int cnt = 0;
        for(int i = 0;i<a.size();i++){
            cnt+=(a[i]!=b[i]);
        }
        return cnt<=2;
    }
    int Find(int x){
        if(x==uf[x])return x;
        return uf[x]=Find(uf[x]);
    }

    void Union(int x,int y){
        int _x = Find(x);
        int _y = Find(y);
        if(_x != _y){
            uf[_y] = _x;
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        uf.resize(n);
        for(int i = 0; i < n; i++){
            uf[i] = i;
        }
        for(int i = 0;i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(valid(strs[i],strs[j])){
                    Union(i,j);
                }
            }
        }

        int res = 0;
        for(int i = 0;i < n;i++){
            res += (uf[i] == i);
        }
        return res;


    }
};
