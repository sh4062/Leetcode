class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left =0;
        int right = 0;
        unordered_map<char,int>mp;
        for(auto i:p)mp[i]++;
        unordered_map<char,int>win;
        vector<int>res;
        int valid = 0;
        while(right<s.size()){
            auto cur = s[right];
            right++;
            if(mp.find(cur)!=mp.end()){
                win[cur]++;
                if(win[cur]==mp[cur]){
                    valid++;
                }
            }
            while(valid==mp.size()){
                if(right-left==p.size())
                res.push_back(left);
                auto cur2 = s[left];
                if(mp.find(cur2)!=mp.end()){
                
                if(win[cur2]==mp[cur2]){
                    valid--;
                }
                win[cur2]--;
            }
            left++;
            }

        }
        return res;

    }
};
