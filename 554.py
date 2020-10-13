class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        sums=sum(wall[0])
        
        #print(sums)
        maxv=0
        intervals={}
        for i in wall:
            maxv=max(maxv,len(i))
        if(maxv==1):return len(wall)
        #if sums==2147483647:return 9999
        for i in wall:
            for j in range(1,len(i)):
                #intervals.add(i[j])
                if i[j-1] not in intervals.keys():
                    intervals[i[j-1]]=1
                else: intervals[i[j-1]]+=1
                i[j]=i[j]+i[j-1]
            #i[-1]=i[-1]+i[-2]
        #print(wall)
        res = 99999999
        for i in intervals:
            #print(i,intervals[i])
            res=min(res,len(wall)-intervals[i])
#         print(len(intervals))
#         for i in intervals:
#             count = 0
#             for j in wall:
#                 if(i not in j):
#                     count=count+1
#             #print(count)
#             res=min(res,count)
                
        #print(res)
        return res
