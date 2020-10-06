class Solution {
public:
    int res=0;
    unordered_map<int,int>memo;
    int arrayNesting(vector<int>& nums) {
        
        for(int i = 0;i<nums.size();i++){
             int c=nums[i];
            set<int> se;
        while(1){
            if(memo.find(c)!=memo.end()){
            res=max(memo[c],res);
            break;
        }
             if(se.find(c)!=se.end()){
                 break;
             }
            se.insert(c);
            c=nums[c];
        }
            memo[nums[i]]=se.size();
            res=max(int(se.size()),res);
        }

        return res;
    }
};
