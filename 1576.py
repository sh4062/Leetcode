class Solution:
    def modifyString(self, s: str) -> str:
        ss='0'+s+'0'
        ss= list(ss)
        for i in range(len(ss)):
            if ss[i]=='?':
                for j in "abc":
                    
                    if (j!=str(ss[i-1])) and (j!=str(ss[i+1])):
                        ss[i]=j
                        break
        
        return ''.join(ss[1:-1])
