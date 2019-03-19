class Solution
{
  public:
    bool isIsomorphic(string s, string t)
    {
        //if(s==NULL&&t==NULL)return true;
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> mp;
        unordered_map<char, char> mp2;
        int i = 0;
        for (; i < s.size(); i++)
        {
            mp[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        string ss = s;
        for (int i = 0; i < ss.size(); i++)
        {
            ss[i] = mp[ss[i]];
            //cout<<ss[i];
        }
        string tt = t;
        for (int i = 0; i < ss.size(); i++)
        {
            tt[i] = mp2[t[i]];
            //cout<<tt[i];
        }

        if (ss == t && tt == s)
            return true;
        else
            return false;
    }
};