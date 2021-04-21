class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        dp=[0]*(len(arr))
        dp[0]=arr[0]
        for i in range(1,len(arr)):
            max_elem=arr[i]
            for j in range(max(i,0),max(i-k,-1),-1):
               
                if(len(arr[j:i+1])>1):
                    max_elem = max(arr[j:i+1])
                
                #print(dp[j],max_elem*(i-j+1),j)
                dp[i] = max(dp[i],max_elem*(i-j+1)+(dp[j-1] if j>0 else 0) )
              
                
        #print(dp)
        return dp[-1]
