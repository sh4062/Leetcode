class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int>s;
        for(const  int &i:nums)
        s.insert(i);
        int cnt = 1;
        int res = 1;
        for(const int &i:s){
            if(!s.count(i-1)){
                int cur = i;
                cnt = 1;
                while(s.count(cur+1)){
                    cur++;

                    cnt++;
                    
                }
                res=max(res,cnt);
                
            }
            
        }
        return res;

    }
};
