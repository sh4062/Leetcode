class Solution:
    
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        minv=999999
        maxv=0
        for i in newInterval:
            for j in intervals:
                if i in range(j[0],j[1]+1):
                    minv=min(minv,j[0])
                    maxv=max(maxv,j[1])
        minv=min(minv,newInterval[0])
        maxv=max(maxv,newInterval[1])
        # print(minv,maxv)
       
        def ol(a,b=newInterval):
           
            if(a[1]<b[0] and a[0]<b[0]):
    
                return True
            if(b[1]<a[0] and b[0]<a[0]):
                
                return True

            return False
        nintervals=list(filter(ol,intervals))
        
        nintervals.append([minv,maxv])
        nintervals.sort(key=lambda x:x[0])
        return nintervals   
        
