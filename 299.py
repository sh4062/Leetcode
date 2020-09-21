class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        a={}
        b=[]
        A=0
        B=0
        for i in range(len(secret)):
            if secret[i]==guess[i]:
                A+=1
                b.append(i)
            else:
                if secret[i] in a:
                    a[secret[i]]+=1
                else:
                    a[secret[i]]=1
        #print(a)
        for i in range(len(secret)):
            if i not in b:
                if guess[i] in a.keys() and a[guess[i]]>0:
                    B+=1
                    #a.pop(guess[i])
                    a[guess[i]]-=1
        
        return str(A)+'A'+str(B)+'B'
