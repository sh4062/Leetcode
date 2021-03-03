class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        res=[]
        dp=[1]*len(nums)
        path=[-1]*len(nums)
        l = 1
        pos=0
        for i in range(len(nums)):
            for j in range(i-1,-1,-1):
                if(nums[i]%nums[j]==0):
                    dp[i]=max(dp[i],dp[j]+1)
                    
                    if dp[i]>l:
                        path[i]=j
                        l=dp[i]
                        pos = i
                    if path[i]==-1:
                        path[i]=j
       
        while(l):
            res.append(nums[pos])
            pos=path[pos]
            l-=1
        
        #print(path)
        return res

