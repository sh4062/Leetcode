class Solution {
public:
    int strStr(string haystack, string needle) {
        const string &h = haystack;
        const string &n = needle;
        int lh = haystack.size();
        int ln = needle.size();
        int i,j;
        for(i=0;i<=lh-ln;++i){
             for (j = 0; j < ln; ++j) {
                if (h[i + j] != n[j]) {
                    break;
                }
             }
             if (j == ln) {
                return i;
            }
        }
        return -1;
    }
};