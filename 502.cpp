class Solution {
public:
    int ret =0;
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //ret= dfs(profits,capital,k,w);
        ret = w;
        //priority_queue<pair<int,int>,vector<pair<int,int>>,[&](pair<int,int>a,pair<int,int>b){}>;
        vector<pair<int,int>>v;
        for(int i = 0;i<capital.size();i++){
            v.push_back({capital[i],profits[i]});
            
        }
        sort(v.begin(),v.end(),[&](pair<int,int>a,pair<int,int>b){ return a.first<b.first;});
        priority_queue<int> pq;
        int index = 0;
        while(k--){
            while(index<v.size() && v[index].first<=w){   
                pq.push(v[index].second);
                index++;
                } 
            
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
            else{
                return w;
            }
        }
        return w;

    }
};
