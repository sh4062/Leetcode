class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        v=[]
        vv=[]
        for i in timePoints:
            ii=i.split(':')
            a1=int(ii[0])
            a2=int(ii[1])
            a=a1*60+a2
            if a1==0:
                v.append(1440+a2)
                v.append(a2)
            else: 
                v.append(a) 
                v.append(1440+a1*60+a2) 
        v.sort()
        #print(v)
        res=1600
        for i in range(1,len(v)):
            res=min(res,v[i]-v[i-1])
        return res
