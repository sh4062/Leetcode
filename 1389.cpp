class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int>res;
        for(int i = 0;i<index.size();i++){
            if(index[i]<res.size())
            res.insert(res.begin()+index[i],nums[i]);
            else{
                res.push_back(nums[i]);
            }
        }
        return res;

    }
};
