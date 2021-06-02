class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int left = 0,right = 0;
        unordered_set<string>S;
        while(right<=s.size()-k){
            if(right+k<=s.size())
            S.insert(s.substr(right,k));
            else break;
            right++;

        }
        return S.size()==pow(2,k);

    }
};
