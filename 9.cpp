class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        x = abs(x);
        if (x < 10)
            return true;
        int rev = 0;
        int xx = x;
        while (x)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        //cout<<rev;
        return (xx == rev);
    }
};