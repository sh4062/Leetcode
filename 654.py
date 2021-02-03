# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def dfs(nums):
        if len(nums)==0:return 
        m=max(nums)
        #print(m)
        a=nums.index(m)
        t=TreeNode(m)
        t.left=dfs(nums[:a-1+1])
        t.right=dfs(nums[a+1:])
        return t
class Solution:
    

    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        return dfs(nums)
