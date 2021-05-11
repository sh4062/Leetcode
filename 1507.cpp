class Solution:
    def reformatDate(self, date: str) -> str:
        d = date.split();
        m={"Jan":1, "Feb":2, "Mar":3, "Apr":4, "May":5, "Jun":6, "Jul":7, "Aug":8, "Sep":9, "Oct":10, "Nov":11,"Dec":12}
        d0=""
        for i in d[0]:
            if(not i.isdigit()):break
            d0+=(i)
        res = d[2]+'-'+"%02d"%m[d[1]]+'-'+"%02d"%int(d0)
        return res
