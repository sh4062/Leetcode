class Solution {
public:
    int specialArray(vector<int>& nums) {
        int range = nums.size();
        while(range){
            int cnt = 0;
            for(auto i:nums){
                if(i>=range)
                cnt++;
            }
            if(cnt==range)return range;
            range--;
        }
        return -1;

    }
};
