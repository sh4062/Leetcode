class Solution {
public:
    void r(vector<int>& nums,int index,vector<vector<int>> &res){
        if(index ==nums.size()){
            res.push_back(nums);
            return;
        }
        else{
            for(int i = index;i<nums.size();i++){
                swap(nums[i],nums[index]);
                r(nums,index+1,res);
                swap(nums[i],nums[index]);
            }
        }
        
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0) return res;
       
        r(nums,0,res);
        return res;
        
        
        
    }
};
