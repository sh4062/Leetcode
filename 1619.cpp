class Solution {
public:
    double trimMean(vector<int>& arr) {
        double res = 0;
        // double maxn=*max_element(arr.begin(),arr.end());
        // double minn=*min_element(arr.begin(),arr.end()); 
        int n = arr.size();
        int nn = int(0.05*double(n));
        sort(arr.begin(),arr.end());
        for(int i = nn;i<n-nn;i++){
            res+=arr[i];

        }

 
        return res/(n-nn-nn);

    }
};
