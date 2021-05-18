class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        if(s.size()<2)return 1;
        int res = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 1;i<s.size();i++){
            if(s[i]==s[i-1]){
                pq.push(cost[i]);
                pq.push(cost[i-1]);
                while(i+1<s.size()&&s[i+1]==s[i]){
                    i++;
                    pq.push(cost[i]);
                }
                while(pq.size()>1){
                    res+=pq.top();
                    pq.pop();
                }pq.pop();
            }

        }
        return res;

    }
};
