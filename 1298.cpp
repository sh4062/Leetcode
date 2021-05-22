class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        unordered_set<int>kk;
        unordered_set<int>boxes;
        queue<int>q;
        for(auto i:initialBoxes){
        boxes.insert(i);
        q.push(i);
        }
        int res = 0;
        while(!q.empty()){
            auto tmp=q.front();
            q.pop();
            // res+=candies[i];
            for(auto k:keys[tmp]){
                kk.insert(k);
            }
            for(auto c:containedBoxes[tmp]){
                boxes.insert(c);
                q.push(c);
            }
        }
        for(auto b: boxes){
            if(status[b]==1||kk.count(b)){
                res+=candies[b];
            }

        }
        return res;



    }
};
