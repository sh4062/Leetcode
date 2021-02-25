class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        memo =dict()
        def dp(i,j)->int:
            if (i,j) in memo:
                return memo[(i,j)]
            #base case 如果一个走完 直接返回另一个剩余长度
            if i==-1:return j + 1
            if j==-1:return i + 1
            if word1[i]==word2[j]:
                memo[(i,j)]= dp(i-1,j-1)
            else:
                memo[(i,j)]=min(dp(i-1,j)+1,dp(i-1,j-1)+1,dp(i,j-1)+1)
            return memo[(i,j)]
        return dp(len(word1)-1,len(word2)-1)
                
