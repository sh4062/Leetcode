class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if((-2*cheeseSlices+tomatoSlices)<0||(-2*cheeseSlices+tomatoSlices)%2!=0)return {};
        if((-tomatoSlices+4*cheeseSlices)<0||(-tomatoSlices+4*cheeseSlices)%2!=0)return {};
        return vector<int>{-(2*cheeseSlices-tomatoSlices)/2,(-tomatoSlices+4*cheeseSlices)/2};

    }
};
