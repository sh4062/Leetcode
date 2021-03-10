class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counter = collections.Counter(tasks)
        #最大任务数量
        m = 0
        #最大任务数量的个数
        c = 0
        for v in counter.values():
            #print(v)
            if m<v:
                m=v
                c=1
            elif m==v:
                c+=1

        return max(len(tasks),(n+1)*(m-1)+c)
