class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0)return false;
        int sums = sum/k;
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int>vis(n,0);
        vector<int>K(k,0);

        return dfs(nums,0,K,sums);

    }
    bool dfs(vector<int>& n,int index,vector<int>&K,int sums){
        for(auto i:K){
            if(i>sums)return false;
        }
        if(index==n.size()){
            for(auto i:K){
            if(i!=sums)return false;
            }
            return true;
        }
        bool flag = false;
        for(int i = 0;i<K.size();i++){
            K[i]+=n[index];
            flag|=dfs(n,index+1,K,sums);
            K[i]-=n[index];
        }
        return flag;

        }

    
};
