class BrowserHistory {
public:
    vector<string>v;
    int index = 0;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        index=0;

    }
    
    void visit(string url) {
        index++;
        v.erase(v.begin()+index,v.end());
        v.push_back(url);

    }
    
    string back(int steps) {
        index -= min(index,steps);
        return v[index];

    }
    
    string forward(int steps) {
        index += min(int(v.size())-1-index,steps);
        return v[index];


    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
