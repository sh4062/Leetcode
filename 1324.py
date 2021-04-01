class Solution:
    def printVertically(self, s: str) -> List[str]:
        
        ss=s.split()
        max_len=0
        for i in ss:
            max_len=max(max_len,len(i))
        words=[i+' '*(max_len-len(i)) for i in ss]
        result=[''.join(i).rstrip() for i in zip(*words)]
        return result
            
