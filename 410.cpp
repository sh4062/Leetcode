class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = 0,r = 0;
        for(auto i:nums){
            l = max(l,i);
            r+=i;
        }
        while(l<r){
            int mid = l+(r-l)/2;
            int need = 1;
            int cur = 0;
            for(auto i:nums){
                if(cur+i>mid){
                    need++;
                    cur = 0;
                }
                cur+=i;
            }
            if(need>m)l=mid+1;
            else r = mid;
        }
        return l;

    }
};
