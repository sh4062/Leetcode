class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
       auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool { return a.second < b.second; };
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> que(cmp);

        vector<int> boundaries;
        for(auto& building : buildings){
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end());
        vector<vector<int>>res;
        int n=buildings.size();
        int index=0;
        for(auto &b:boundaries){
            //cout<<b;
            //对每个building进行判断，当前building的左边缘小于boundary时，将其加入优先队列中
            
            while(index<n&&buildings[index][0]<=b){
                que.push({buildings[index][1],buildings[index][2]});
                index++;
            }
            //不断检查优先队列的队首元素是否「包含该横坐标」，如果不「包含该横坐标」，我们就将该队首元素弹出队列
            while(!que.empty()&&que.top().first<=b){
                que.pop();
            }
            int maxh = que.empty()?0:que.top().second;
            if(res.size()==0||res.back()[1]!=maxh){
                res.push_back({b,maxh});
            }
        }
        return res;

        

    }
};
