class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        s11=list(s1)
        s22=list(s2)
        s11.sort()
        s22.sort()
        cnt = 0
        cnt2 = 0
        for i in range(len(s22)):
            if(s11[i]>=s22[i]):cnt+=1
            if(s11[i]<=s22[i]):cnt2+=1

        return cnt==len(s11) or cnt==0 or cnt2==0 or cnt2==len(s11)
