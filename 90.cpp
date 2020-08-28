class Solution {
public:
    set<vector<int>> res;
        vector<int> t;
    void dfs(int a,vector<int>& nums){
        if(a>=nums.size())return;
        t.push_back(nums[a]);
       //cout<<t.size()<<endl;
        res.insert(t);
        for(int i =1;a+i<nums.size();i++)
        dfs(a+i,nums);
        t.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        res.insert(t);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
        dfs(i,nums);
        }
        return vector<vector<int>>(res.begin(),res.end());
        
   }
};
