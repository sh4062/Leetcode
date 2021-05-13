class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
         int res = 0;
        int l = arr.size()+1;
        int prefixSum [l];
        for (int i = 1; i < l; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
        }
        for (int i = 0; i + k <= l-1; i++) {
            if ((prefixSum[i + k] - prefixSum[i]) / k >= threshold) {
                res++;
            }
        }
        return res;
    }
};
