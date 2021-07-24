class LRUCache {
public:
    const int sz;
    list<pair<int,int>>dl;//v
    unordered_map<int,list<pair<int,int>>::iterator>mp;// k v
    LRUCache(int capacity):sz(capacity) {
        
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }else{
            dl.splice(dl.begin(),dl,mp[key]);
            
            return (*mp[key]).second;
        }

    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            //更新
            auto tmp = mp[key];
            tmp->second=value;
            dl.splice(dl.begin(),dl,tmp);
        }else{
            //插入
            if(dl.size()>=sz){//满了
                
                auto tmp = dl.back().first;
                dl.pop_back();
                mp.erase(tmp);

            }
            dl.emplace_front(pair<int,int>{key,value});
            mp[key]=dl.begin(); 
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
