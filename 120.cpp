class Solution {
    int dp[1000][1000]={0};
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()<=1)return triangle[0][0];
        int id = 0;
        vector<int> ids;
        // for(int i = 0;i<triangle.size();i++){
        //     ids.push_back(id);
        //     id+=i+1;
        // }
        
         for(int j =0;j<triangle[triangle.size()-1].size();j++){
             dp[triangle.size()-1][j]=triangle[triangle.size()-1][j];
         }
         for(int i = triangle.size()-2;i>=1;i--){
            for(int j =0;j<triangle[i].size();j++){
                
//                 if(j==0){
//                     dp[i][j]=dp[i+1][0]+triangle[i][j];
//                 }
//                 else if(j==triangle[i].size()-1){
//                     dp[i][j]=dp[i+1][triangle[i+1].size()-1]+triangle[i][j];
                    
//                 }else{
                if(j==0)
                    dp[i][j]=min(dp[i+1][j*2],dp[i+1][j*2+1])+triangle[i][j];
                else{
                    dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
                }
                //cout<<dp[i][j]<<" ";
                //}
            }
             //cout<<endl;
        }
       
        
//         for(auto a:ids){
//             cout<<a;
            
//         }
        int res=INT_MAX;
        for(int i = 0;i<triangle[1].size();i++){
            
            res=min(res,dp[1][i]);
        }
        return res+triangle[0][0];
    }
};