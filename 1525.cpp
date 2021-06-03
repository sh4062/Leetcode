class Solution {
public:

    int numSplits(string s) {
         int res = 0;
        unordered_map<char, int> hash, mp;
        for (auto x : s) hash[x] ++;
        int cnt = hash.size();

        for (int i = 0; i < s.size(); i ++ )
        {
            char c = s[i];
            mp[c] ++, hash[c] --;

            if (hash[c] == 0) cnt --;
            if (mp.size() == cnt) res ++;
        }

        return res;



    }
};
