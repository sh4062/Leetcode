class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int res = 0;
        int presumfix = 0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i = 0;i<A.size();i++){
            presumfix+=A[i];
            //cout<<presumfix<<endl;
            if(mp.find(presumfix-S)!=mp.end()){
                res+=mp[presumfix-S];
                

            }
                mp[presumfix]+=1;
            
        }
        //cout<<mp[1];
        return res;

    }
};
