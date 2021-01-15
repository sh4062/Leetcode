class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x:x[0])
        #print(points)
        a= 1
        if len(points)==0:return 0
        if len(points)==1:return 1
        _range=[points[0][0],points[0][1]]
        for p in points[1:]:
            #在范围内
            if p[0]<=_range[1]:
                #print(p)
                _range[1]=min(p[1],_range[1])
                _range[0]=max(p[0],_range[0])
            
            else:
                a+=1
                _range[0]=p[0]
                _range[1]=p[1]
                
        return a
        
