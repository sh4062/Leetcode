class Solution:
    def comp(self,a,b):
        return 1 if str(a)+str(b)<str(b)+str(a) else -1

    def largestNumber(self, nums: List[int]) -> str:
        res=""
        nums.sort(key=functools.cmp_to_key(self.comp))
        nums=list(map(str,nums))
        #print(nums )
        res = "".join(nums)
        if res[0] == "0":
            res = "0"
        return res
