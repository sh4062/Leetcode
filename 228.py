class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if(len(nums)<1):
            return nums
        res=[]
        s1=nums[0]
        s2=nums[0]
        for i in range(1,len(nums)):
            if(nums[i]-nums[i-1]==1):
                s2+=1
            else:
                if s1!=s2:
                    res.append(str(s1)+'->'+str(s2))
                else:
                    res.append(str(s1))
                s1=nums[i]
                s2=s1
        if s1!=s2:
            res.append(str(s1)+'->'+str(s2))
        else:
            res.append(str(s1))        
        return res


