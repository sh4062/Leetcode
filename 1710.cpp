class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>a,vector<int>b){return a[1]>b[1];});
        int res = 0;
        for(auto i:boxTypes){
            if(truckSize==0)return res;
            for(int j = 0;j<i[0];j++){
                res+=i[1];
                truckSize--;
                if(truckSize==0)return res;
            }


        }
        return res;

    }
};
