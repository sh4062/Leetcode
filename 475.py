
class Solution:
    def find_ge(self,a, x):
        "Find leftmost item greater than or equal to x"
        i = bisect_left(a, x)
        if i != len(a):
            return a[i]
        raise ValueError
    
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        c=0
        # ho=set(houses)
        # he=set(heaters)
        # hes=he.copy()
        # #
        # while (ho & hes) != ho:
        #     c+=1
        #     #hes=he.copy()
        #     #print((ho & hes))
        #     for i in he:
        #         for j in range(1,c+1):
        #             hes.add(i+j)
        #             hes.add(i-j)
        #     #he=hes
        #     #print(he)
        houses.sort()
        heaters.sort()
        dist=[]
        for i in houses:
            #print(bisect_left(heaters,i))
            res=bisect_left(heaters,i)
            if(res==0):
                dist.append(abs(heaters[res]-i))
            elif (res>= len(heaters)):
                dist.append(abs(heaters[-1]-i))
            else:
                #print(res-1)
                dist.append(min(abs(heaters[res]-i),abs(heaters[res-1]-i)))
            
        #print(dist)
        return max(dist)
