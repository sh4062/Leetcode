class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []
        if len(digits) == 0:
            return res
        length = len(digits)
        l = [[],[],['a','b','c'],['d','e','f'],['g','h','i'],['j','k','l'],['m','n','o'],\
        ['p','q','r','s'],['t','u','v'],['w','x','y','z']]    
        if(length==1):return l[int(digits)]
        tmpl = l[int(digits[0])]
        for ii in range(1,length):
            for i in itertools.product(tmpl,l[int(digits[ii])]):
                res.append(i[0]+i[1]);
            tmpl = res
            res = []
                
        return tmpl