class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        res=sum(nums[:k])
        cur=res
        for i in range(k,len(nums)):
            cur=cur-nums[i-k]+nums[i]
            res=max(res,cur)

            

        return res/k
