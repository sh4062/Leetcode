class Solution {
public:

    int countTriplets(vector<int>& arr) {

         int res = 0;

        for (int i = 0; i < arr.size(); i++) {
            int t = arr[i];
            for (int k = i + 1; k < arr.size(); k++) {
                t ^= arr[k];
                if (t == 0) {
                    // j 无所谓呐，i~k任意一个数都行
                    res += k - i;
                }
            }
        }
        return res;
    }
};
