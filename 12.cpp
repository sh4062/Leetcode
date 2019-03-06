#include <bits/stdc++.h>
using namespace std;
static const auto __ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}();
class Solution
{
  public:
    Solution()
    {
        dict[1] = "I";
        dict[4] = "IV";
        dict[5] = "V";
        dict[9] = "IX";
        dict[10] = "X";
        dict[40] = "XL";
        dict[50] = "L";
        dict[90] = "XC";
        dict[100] = "C";
        dict[400] = "CD";
        dict[500] = "D";
        dict[900] = "CM";
        dict[1000] = "M";
    }
    string intToRoman(int num) {//Input is guaranteed to be within the range from 1 to 3999.
        string a = "";
        int value[]=    {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};
        for(int i=0;num!=0;i++){
            while(num>=value[i]){
                num=num-value[i];
                a= a+dict[value[i]];
            }
        }
        return a;


        
    }
    ~Solution()
    {
        dict.clear();
    }

  private:
    unordered_map<int,string> dict;
};

/*
public static String intToRoman(int num) {
    String M[] = {"", "M", "MM", "MMM"};
    String C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    String X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    String I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
} 
mmp啊
*/