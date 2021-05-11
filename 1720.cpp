class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.push_back(first);
        for(int i = 1;i<=encoded.size();i++){
            res.push_back(encoded[i-1]^res[i-1]);
        }
        return res;


    }
};
