class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r=n-1;
        while (l <= r)
        {
            
            while(l<r&&nums[l]==nums[l+1]) ++l;
            while(l<r&&nums[r]==nums[r-1]) --r;
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] <nums[r])
            {                                                //右边是有序的
                if (target > nums[mid] && target <= nums[r]) //在右边
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else
            { //左边有序
                if (target >= nums[l] && target < nums[mid])
                { //在左边
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        return false;

    }
};
