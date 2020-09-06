class Solution:
    
    def minMoves(self, nums: List[int]) -> int:
        # a=max(nums)
        # n=len(nums)-1
        # nums.sort()
        # if(n<=0):return 0
        # c=0
        # mm=
        # mn=
        # while(nums[0] != nums[-1]):
        #    # print(nums)
        #     cc=nums[-1]-nums[0]
        #     for i in range(0,n):
        #         nums[i]+=cc
        #     nums.sort()
        #     c+=cc
        return sum(nums) - len(nums) * min(nums)
            
            
        
        #return c
