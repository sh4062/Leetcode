class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        int idx=0;
        int pre=1;
        while(candies>=0){
            idx%=num_people;
            if(candies>=pre)
            res[idx]+=pre;
            else break;
            candies-=pre;
            pre++;
            idx++;
        }
        if(candies>0)res[idx]+=candies;
        return res;
    }
};
