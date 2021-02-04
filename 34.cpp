class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)return vector<int>{-1,-1};
        vector<int> res;
        int left = 0,right=nums.size();
        while(left<right){
            int mid =(left+right)/2;
            if(nums[mid]==target){
                right=mid;
            }else if(nums[mid]<target){
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid;
            }
        }
        
        if(left>=nums.size()||nums[left]!=target)left=-1;
        res.push_back(left);
        left=0;
        right=nums.size();
        while(left<right){
            int mid =(left+right)/2;
            if(nums[mid]==target){
                left=mid+1;
            }else if(nums[mid]<target){
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid;
            }
        }
        //cout<<left<<endl;
        if(left>=1&&nums[left-1]!=target)left=0;
        res.push_back(left-1);
        return res;


    }
};
