class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        trantab = str.maketrans({key: ' ' for key in string.punctuation})
        paragraph = paragraph.translate(trantab)
        s=paragraph.lower().split()
        
        
        ss={}
        
        for i in s:
            
            if i not in banned:
                if i not in ss.keys():
                    ss[i]=1
                else:
                    
                    ss[i]+=1
        
        ss=sorted(ss.items(), key=lambda x: -x[1])
        #print(ss)
        return  ss[0][0]
