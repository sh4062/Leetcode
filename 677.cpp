class MapSum {
public:
    map<string,int>mp;
    /** Initialize your data structure here. */
    MapSum() {

    }
    
    void insert(string key, int val) {
        mp[key]=val;

    }
    
    int sum(string prefix) {
        int ans = 0;
        string s;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            s = it->first;
            if(s.find(prefix)==0)
            {
                ans += (it->second);
            }
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
