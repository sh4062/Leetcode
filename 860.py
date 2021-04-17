class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        res = [0,0,0]
        for i in bills:
            if i==5:
                res[0]+=1
            elif i==10:
                res[0]-=1
                if res[0]<0:return False;
                res[1]+=1
            elif i==20:
                if res[1]>0:
                    res[1]-=1
                    res[0]-=1
                    if res[0]<0:return False;
                else:
                    res[0]-=3
                    if res[0]<0:return False;
            
        for i in res: 
            if i<0:
                return False;
        return True;
                
       
