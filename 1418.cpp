class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
 vector<vector<string>>res;
        set<string>food;       
        map<int,unordered_map<string,int>>m;
        for(auto order:orders){
            m[stoi(order[1])][order[2]]++;  
            food.insert(order[2]);            
        }
        vector<string>head(food.begin(),food.end());
        head.insert(head.begin(),"Table");
        res.push_back(head);
        for(auto p=m.begin();p!=m.end();p++){
            vector<string>t;
            t.push_back(to_string(p->first));
            for(auto q=food.begin();q!=food.end();q++){
                t.push_back(to_string(p->second[*q]));
            }
            res.push_back(t);
        }
        return res;
    }
};
