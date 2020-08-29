class Solution {
public:
    int res=INT_MAX;
    unordered_map<int,int>mp;
    void dfs(int a,int s,vector<int>& c,int cc,int& amount){
        if(a==c.size())return;
            if(s>amount)return;
        if(s==amount){
            cout<<cc<<endl;
            res=min(res,cc);
            return;
        }
        else if(s!=amount&&(amount-s)%c[a]==0){
            //cout<<cc+(amount-s)/c[a]<<endl;
            res=min(res,cc+(amount-s)/c[a]);
            return;
        }

        // if(mp.count(s)&&mp[s]>res){
        //    return;
        // }
        for(int k=(amount-s)/c[a];k>=0&& k + cc<res;k--){
            if(cc+k<res)
            dfs(a+1,s+k*c[a],c,cc+k,amount);
            //  if(!mp.count(s-k*c[a]))
            //  mp[s-k*c[a]]=cc+k;
            // else{
            //      mp[s-k*c[a]]=min(cc+k, mp[s-k*c[a]]);
            // }
       // mp[s]=cc;
        //mp[s]++;
            }
        
    }
    int coinChange(vector<int>& coins, int amount) {
//        vector<vector<int>>dp(coins.size(),vector<int>(coins.size(),0));
        sort(coins.rbegin(), coins.rend());
//         for(int i=1;i<=coins.size();i++){
//             for(int j=0;j<=amount;j++){
//                 for(int k=1;k<=amount/coins[i-1];k++){}
//                 if(j-coins[i-1]>0){
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-k*coins[i-1]]+k*coins[i-1]);
                    
//                 }else{
                    
//                 }
//                 if(amount==dp[i][j]){
//                     res=min(res,);
//                 }
//             }
            
            
//         }
            
//         }
        dfs(0,0,coins,0,amount);
        //cout<<res;
        return res==INT_MAX?-1:res;
    }
};
