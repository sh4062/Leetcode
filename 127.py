from collections import deque
class Solution:

    # def dist_w(self,a,b):
    #     res=0
    #     for i in range(len(a)):
    #         if a[i]!=b[i]:
    #             res+=1
    #         if(res>1):break;
    #     return res==1
    def next_char(self,ch):
        return chr(((ord(ch) + 1-97)%26+97))
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:return 0
        # if beginWord == endWord: self.rets=min(self.rets,self.ret) 
        step=1
        q = deque()
        visited=set()
        wk=set(wordList)
        q.append(beginWord)
        while(len(q)>0):
            sz=len(q)
            for n in range(sz):
                cur=q[0];
                q.popleft();
                if(cur==endWord):return step
                # q.pop(0);
                pwords=[]
                for i in range(len(cur)):
                    tmp=cur[:i]+self.next_char(cur[i])+cur[i+1:]
                    pwords.append(tmp)
                    for j in range(24):
                        tmp=tmp[:i]+self.next_char(tmp[i])+tmp[i+1:]
                        pwords.append(tmp)
                    
                #print(pwords)
                for i in pwords:
                    if i in wk and i not in visited:
                          visited.add(i)
                          q.append(i)
                        
            step+=1
                               
        return 0
