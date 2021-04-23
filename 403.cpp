class Solution {
public:
    bool canCross(vector<int>& stones) {
        int goal = stones.back();
        vector<vector<int>>dp (stones.size(),vector<int>(stones.size()+2,0));
        dp[0][0]=1;
        for(int i = 1;i<stones.size();i++){
            for(int j = 0;j<i;j++){
                int k = stones[i]-stones[j];
                if(k<stones.size()+1)
                dp[i][k] =dp[j][k-1]||dp[j][k]||dp[j][k+1];
            }

        }
        for(auto i:dp[stones.size()-1]){
            //cout<<i<<endl;
            if(i)return true;
        }
        return false;

    }
};
