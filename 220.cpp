class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //在下标范围
        int left = 0;
        int right = 0;
        set<long>S;
        for(int i= 0;i<nums.size();i++){
            auto lb=S.lower_bound(long(nums[i])-t);
            if((lb!=S.end())&&*lb<=(long)nums[i]+t)return true;
            S.insert(nums[i]);
            if (i >= k) S.erase(nums[i - k]);
        }
        return false;

    }
};
