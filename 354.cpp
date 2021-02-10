class Solution {
public:
    int lenOflis(vector<int>n){
        vector<int>dp(n.size(),1);
        for(int i = 0;i<n.size();i++){
            for(int j = 0;j<i;j++){
                if(n[i]>n[j])
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        int max_index=max_element(dp.begin(),dp.end())-dp.begin();
        return dp[max_index];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size()==0)return 0;
        sort(envelopes.begin(),envelopes.end(),[](vector<int>a,vector<int>b){
            if(a[0]!=b[0])
            return a[0]<b[0];
            else return a[1]>b[1];});
        //sort(envelopes.begin(),envelopes.end(),[](vector<int>a,vector<int>b){return a[1]<b[1];});
        vector<int> aux;
        for(auto i:envelopes){
            //cout<<i[0]<<" "<<i[1]<<endl;
            aux.push_back(i[1]);
        }
        return lenOflis(aux);
    }
};
