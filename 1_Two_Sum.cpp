class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        int n = nums.size();
        vector <int> res(2);
        for(int i=0;i<n;++i){
            if(m.find(target-nums[i])!=m.end())
            {
                res[0]=m[target-nums[i]];
                res[1]=i;
                
                break;
            }
            else{
                m[nums[i]]=i;
            }
        }
        m.clear();
        return res;
    }
};
