class Solution {
public:
    unordered_map<int,int>mp;
    int maxOperations(vector<int>& nums, int k) {
        int res  = 0;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto i:nums){
            if(mp.find(k-i)!=mp.end()){
                if(mp[i]>0&&mp[k-i]>0){
                    if(i==k-i){
                        if(mp[i]>=2){
                             res++;
                             mp[i]--;
                             mp[k-i]--;}
                        }else{
                    res++;
                    mp[i]--;
                    mp[k-i]--;}

                    }

                
            }
        }
        return res;
    }
    
};
