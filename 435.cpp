class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x:x[1])#
        res=1
        cur_end=intervals[0][1]
        print(intervals)
        for i in intervals:
            if i[0]<cur_end:
                continue
            cur_end = i[1]
            #print(end)
            res+=1

        #print(res)
        return len(intervals)-res
