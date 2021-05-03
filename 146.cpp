class LRUCache {
public:
    
    list<pair<int,int>>l;
    int c;
    LRUCache(int capacity) {
        c=capacity;

    }
    
    int get(int key) {
          for (auto it=l.begin(); it!=l.end(); ++it){
            if((*it).first==key){
            l.splice(l.begin(),l,it);
            return (*it).second;
            }
        }
        return -1;

    }
    
    void put(int key, int value) {
        for (auto i=l.begin(); i!=l.end(); ++i){
            if((*i).first==key){
                (*i).second = value;
                l.splice(l.begin(),l,i);
                return;
            }
        }
        l.emplace_front(key,value);
        if(l.size()>c){
            l.pop_back();
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
