class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = cardPoints.size()-k;
        int left = 0,right = 0;
        int c = 0;
        int res = INT_MAX;
        while(right<cardPoints.size()){
            c+=cardPoints[right];
            right++;
            while(right-left+1>l){
                res = min(res,c);
                c-=cardPoints[left];
                left++;
                

            }

        }
        return accumulate(cardPoints.begin(),cardPoints.end(),0)-res;

    }
};
