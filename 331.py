class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        #叶子节点总是比非叶子节点多1
        degree = 1
        for i in preorder.split(','):
            if degree ==0:
                return False
            if i == '#':
                degree-=1
            else:
                degree+=1
        return degree==0
