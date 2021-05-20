class Solution {
public:
    int f(string s)
    {
        sort(s.begin(),s.end());
        int count=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
                count++;
            else
                break;
        }
        return count;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res;
        vector<int>fqueries;
        vector<int>fwords;
        for(auto j:queries){
            fqueries.push_back(f(j));
        }
        for(auto j:words){
            fwords.push_back(f(j));
        }
        for(auto i:fqueries){
            int cur = 0;
            for(auto j:fwords){
                if(i<j)cur++;
            }
            res.push_back(cur);
        }
        return res;
        

    }
};
