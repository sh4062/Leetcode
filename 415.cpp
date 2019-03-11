class Solution
{
  public:
    string addStrings(string num1, string num2)
    {
        string res;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int flag = 0;
        int i = 0;
        for (; i < min(num1.size(), num2.size()); i++)
        {

            int t = num1[i] - '0' + num2[i] - '0' + flag;

            res = res + to_string((t) % 10);
            if (t > 9)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
        if (i < num1.size())
        {
            for (; i < num1.size(); i++)
            {
                int t = num1[i] - '0' + flag;

                res = res + to_string((t) % 10);
                if (t > 9)
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }
        }
        if (i < num2.size())
        {
            for (; i < num2.size(); i++)
            {
                int t = num2[i] - '0' + flag;

                res = res + to_string((t) % 10);
                if (t > 9)
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }
        }
        if (flag)
            res = res + '1';
        reverse(res.begin(), res.end());
        return res;
    }
};