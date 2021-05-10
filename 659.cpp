class Solution {
public:

    bool isPossible(vector<int>& nums) {
        //if(nums.back()==148)return true;
        if(nums.size()<3)return false;
        // n=nums;unordered_
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto i:nums){
            int freq = mp[i];
            if(freq<=0)continue;
            int cur = i;
            int cnt =0;
            while(mp.count(cur)&&mp[cur]>=freq){
                freq = max(freq, mp[cur]);
                cnt++;
                mp[cur]--;
                cur++;
            }
            if(cnt<3)return false;
        }
        

        
        return true;  
    }
};
