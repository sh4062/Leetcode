class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int res = 0;
        vector<pair<int,int>> v;
        unordered_map<int,int> mp;//记录每个标签多少次
        int count=0;//记录用了多少个
        int n=values.size();
        for(int i=0;i<n;i++)  v.push_back(pair<int,int>(values[i],labels[i]));
        sort(v.rbegin(),v.rend());
        for(int i = 0;i<n;i++){
            if(mp[v[i].second]<use_limit){
                res+=v[i].first;
                mp[v[i].second]++;
                count++;
                if(count==num_wanted)return res;
            }

        }
        return res;


    }
};
