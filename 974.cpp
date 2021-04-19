class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sum = 0;
        int res = 0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i = 0;i<A.size();i++){
            sum+=A[i];
            while(sum<0)sum+=K;
            int mod = sum%K;
            //cout<<mod<<endl;
            if(mp.find(mod)!=mp.end()){
                res+=mp[mod];
            }
            mp[mod]++;

        }
        return res;

    }
};
