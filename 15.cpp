//naive solution tle
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> res;
//         if(nums.size()<3)return res;
//         sort(nums.begin(),nums.end());
//         for(int i =0;i<nums.size();i++){
//             for(int j =i+1;j<nums.size();j++){
//                 for(int k =j+1;k<nums.size();k++){
//                     if(i!=j&&j!=k&&i!=k){
//                         if(nums[i] +nums[j]+nums[k]==0){
//                             int iii = 0;
//                             for(auto ii:res){
//                                 if(!(nums[i]==ii[0]&&nums[j]==ii[1]&&nums[k]==ii[2])){
//                                     iii++;
//                                 }
//                             }
//                             if(iii==res.size())
//                             res.push_back(vector<int>{nums[i],nums[j],nums[k]});
//                         }
//                     }
                    
//                 }
//             }
//         }
//         return res;
        
//     }
// };
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3)return res;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size()-2;i++){
           int num = nums[i];
           int target = 0 - num;
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int l=i+1, r=nums.size()-1; l<r; ) {
                if(nums[l]+nums[r] > target)                     
                    r--;
                else if (nums[l]+nums[r] < target) 
                    l++;
                else {
                    // nums[l] + nums[r] == target 
                    res.push_back({nums[i], nums[l], nums[r]}); 

                    // skip duplicates
                    while( l<nums.size()-1 && nums[l]==nums[l+1]) l++; 
                    while( r>0 && nums[r]==nums[r-1]) r--;
                                            
                    l++;
                    r--;                    
                    
                } 
                
            }              
        }
        return res;
        
    }
};