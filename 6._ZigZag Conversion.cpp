class Solution {
public:
    string convert(string s, int numRows) {
        int a = s.size();
        int b = numRows;
        if(b<=1) return s;
        int i, j;
        string res = "";
        
        for (j = 0; j < a; j += 2 * b - 2) {
            res.push_back(s[j]);
        }
        for (i = 1; i < b - 1; ++i) {
            for (j = 0; j < a; j += 2 * b - 2) {
                if (j + i < a) {
                    res.push_back(s[j + i]);
                }
                if (j + 2 * b - 2 - i < a) {
                    res.push_back(s[j + 2 * b - 2 - i]);
                }
            }
        }
        for (j =b  - 1; j < a; j += 2 * b - 2) {
            res.push_back(s[j]);
        }
        return res;
        
    }
};
