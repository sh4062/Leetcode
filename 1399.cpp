class Solution {
public:
    int sumd(int n){
        int r = n%10;
        n=n/10;
        while(n){
            //cout<<n/10;
            r+=n%10;
            n=n/10;
        }
        return r;
    }
    vector<vector<int>>v;
    int countLargestGroup(int n) {
        int g  = 0;
        set<int> s;
        vector<vector<int>>v;
        v.resize(10001);
        for(int i = 1;i<=n;i++){
            if(s.find(sumd(i))==s.end()){
            s.insert(sumd(i));
            v[sumd(i)].push_back(i);
            }else{v[sumd(i)].push_back(i);
                
            }
        }
        int max = 0;
        for(int i = 1;i<=s.size();i++){
            if(v[i].size()>max)max=v[i].size();
        }
        int c = 0;
        for(int i = 1;i<=s.size();i++){
            if(v[i].size()==max)c++;
        }
        return c;
        
    }
};