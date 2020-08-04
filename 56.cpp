class Solution {
public:

    bool inter(vector<int> a,vector<int> b){
        if(a[0]>b[0]){
            swap(a,b);
        }
        if(a[1]<b[0]){
            return false;
        }
        return true;
        
    }
    vector<vector<int>> merges(vector<vector<int>>& intervals) {
        set<vector<int>>res;
        for(auto i:intervals){
            res.insert(i);
        }
        for(int i = 0;i<intervals.size()-1;i++){
            for(int j = i+1;j<intervals.size();j++){
                if(inter(intervals[i],intervals[j])){
                    int minV = INT_MAX;
                    int maxV = INT_MIN;
                    minV=min(intervals[i][0],intervals[j][0]);
                    maxV=max(intervals[i][1],intervals[j][1]);
                    res.erase(intervals[i]);
                    res.erase(intervals[j]);
                    res.insert(vector<int>{minV,maxV});
                    intervals.assign(res.begin(), res.end());
                    return merges(intervals);
                }
            }
        }
        return intervals;
        
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)return(intervals);
        return merges(intervals);
        
        
        
    }
    
};