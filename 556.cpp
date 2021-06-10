class Solution {
public:
    int nextGreaterElement(int n) {
        if(n < 10) return -1;
        string str = to_string(n);
        next_permutation(str.begin(), str.end());
        long val = stol(str);
        if(val > INT_MAX || val <= n) return -1;
        return val;

    }
};
