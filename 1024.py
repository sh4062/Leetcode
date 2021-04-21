class Solution:
    def videoStitching(self, clips: List[List[int]], T: int) -> int:
        maxlen=[0]*(T+1)
        for c in clips:
            for i in range(c[0],min(c[1]+1,T)): 
                maxlen[i] = max(maxlen[i],min(c[1],T))
       
        index = 0
        res = 0
        while(index<T):
            if maxlen[index]==index:
                return -1
            index = maxlen[index]
            res+=1

        return res 
