class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int a = accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        int b = accumulate(bobSizes.begin(),bobSizes.end(),0);
        vector<int>res(2,0);
        for(auto i:aliceSizes){
            for(auto j:bobSizes){
                if(a+j-i==b+i-j){
                    res[0]=i;
                    res[1]=j;
                    return res;
                }
            }
        }
        return res;

    }
};
