class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int res = 0, n = nums.size();
        int sumOdd = 0, sumEven = 0, leftOdd = 0, leftEven = 0,rightOdd = 0, rightEven = 0;
        for(int i = 0; i< n; i++){
            if(i%2 == 0) {
                sumEven += nums[i];
            }else{
                sumOdd += nums[i];
            } 
        }
        
        for(int i = 0; i< n; i++){
            //计算leftOdd,leftEven
            if(i % 2 == 0){ 
                leftEven += nums[i];}
            else{
                leftOdd += nums[i];    
            } 
            //计算rightOdd,rightEven
            rightOdd = sumEven - leftEven;
            rightEven = sumOdd- leftOdd;
            
            //remove这个元素后 左右情况变化
            if(i%2 == 0) {
                rightEven -= nums[i]; //==> rightEven turns into rightOdd
            }else{ 
                rightOdd -= nums[i];  //==> rightOdd turns into rightEven
            }
            
            if(leftOdd + rightOdd == leftEven + rightEven) res++;
        }
        return res;
    }
};
