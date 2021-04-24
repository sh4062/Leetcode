class Solution {
public:
    vector<int>n;
    vector<int>memo;
    int dfs(int aux,int c,int target){
        
        if(c>target)return 0;
        if(c==target){
            return memo[c];
            
        }
        if(memo[c]!=-1){
            return memo[c];
        }
        int res = 0;
        for(int i = 0;i<n.size();i++){
            
            res+=dfs(aux+1,c+n[i],target);
            
        }
        if(c<=target)
        memo[c]=res;
        return res;
       

    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums;
        memo.resize(target+1,-1);
        int a = dfs(0,0,target);
        return -a;


    }
};
