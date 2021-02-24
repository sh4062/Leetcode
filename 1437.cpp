class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int index0 = -1;
        
        for(int i = 0;i<nums.size();i++){
            index0++;
            if(nums[i]==1){break;
            }
        }
        int index1=index0+1;
        for(index1;index1<nums.size();index1++){
            if(nums[index1]==1){
                if(index1-index0<=k){
                    return false;
                }
                index0=index1;

            }

        }
        return true;

    }
};
