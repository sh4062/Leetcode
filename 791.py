class Solution:
    def customSortString(self, order: str, str1: str) -> str:
        d={j:i for i,j in enumerate(order)}
        def f(a):
            if a in d: 
                return d[a]
            else: return -1
        aa=list(str1)
        aa.sort(key=f)
        
        return "".join(aa)
        
