class Solution {
public:
    int SS;
    int c=0;
    void dfs(int a,int s,vector<int>& nums){
        
        // if(s>SS){
        //     return;
        // }
        if(s==SS&&a==int(nums.size()-1)){
            c++;
            return;
        }
        if(a+1>=int(nums.size())){
            //cout<<a<<" "<<nums.size();
            return;
        }
        dfs(a+1,s+nums[a+1],nums);
        dfs(a+1,s-nums[a+1],nums);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size()<1)return 0;
        if(nums.size()==1&&nums[0]==S)return 1;
        if(nums.size()==1&&nums[0]==-S)return 1;
        if(nums.size()==1&&nums[0]!=S)return 0;
        SS=S;
        dfs(-1,0,nums);
        return c;
    }
};
