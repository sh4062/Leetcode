class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        a1,a2=a.split('+')
        b1,b2=b.split('+')
        a2=a2[:-1]
        b2=b2[:-1]
        a1=int(a1)
        a2=int(a2)
        b1=int(b1)
        b2=int(b2)
        c1=a1*b1-a2*b2
        c2=a1*b2+a2*b1
        return str(c1)+'+'+str(c2)+'i'
