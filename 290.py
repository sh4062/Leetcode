class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        ss=s.split()
        if(len(ss)!=len(pattern)):return False;
        d={}
        #dd={}
        sss=set();
        for i in range(len(ss)):
            if pattern[i] not in d.keys() and  ss[i] in sss:
                return False
            d[pattern[i]]=ss[i]
            sss.add(ss[i])
            # dd[pattern[i]]=ss[i]
        print(d)
        for i in range(len(ss)):
            #print(d[ss[i]])
            if d[pattern[i]]!=ss[i]:
                return False
        return True
