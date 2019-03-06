//大整数乘法
//原来根据位置有技巧 i,j-> i+j,i+j+1
//然后按位加就行了
class Solution
{
  public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        string res;
        vector<int> tmp(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                int mulx = (num1[i] - '0') * (num2[j] - '0');
                int pos1 = i + j;
                int pos2 = i + j + 1;
                int sum = mulx + tmp[pos2];
                tmp[pos1] += sum / 10;
                tmp[pos2] = sum % 10;
            }
        }
        //cout<<tmp[1];
        int i = 0;
        for (i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != 0)
                break;
        }
        for (i; i < tmp.size(); i++)
        {
            res += to_string(tmp[i]);
        }

        return res;
    }
};