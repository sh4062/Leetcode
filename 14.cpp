static const auto __ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix;
        if (strs.size() == 0)
            return prefix;
        for (int i = 0; i < strs[0].size(); i++)
        {
            int t = 1;
            for (t; t < strs.size(); t++)
            {
                if (strs[t][i] != strs[0][i])
                    return prefix;
            }

            prefix += strs[0][i];
        }

        return prefix;
    }
};