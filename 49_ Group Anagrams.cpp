class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        //Using hash to save substr
        for (string str : strs) {
            string t = str;
                       // cout<<t;
            sort(t.begin(), t.end());
            m[t].push_back(str);
        }
       // cout<<m["e"]
        for (auto a : m) {
           // cout<<a.second;
            res.push_back(a.second);
        }
        return res;
    }
};
