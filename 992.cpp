class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int left = 0,right = 0;
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> window;
        int cur = 0;
        while(right<n){
            window[nums[right]]++;
             right++;
            
            //if(now==k)res++;
            while(window.size()>k-1){
                window[nums[left]]--;
                if(window[nums[left]]==0)window.erase(nums[left]);
                 
                left++;
            }
            //cout<<left<<":"<<right<<endl;
            res+=right-left;
            
        }
        int res2 = 0;
        right=0,left=0;
        window.clear();
        while(right<n){
            window[nums[right]]++;
             right++;

            //if(now==k)res++;
            while(window.size()>k){
                window[nums[left]]--;
                if(window[nums[left]]==0)window.erase(nums[left]);
                left++;
            }
            //cout<<left<<":"<<right<<endl;
            res2+=right-left;
            
        }
        return res2-res;

    }
};
