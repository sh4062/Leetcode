//数prime
class Solution
{
  public:
    bool isPrimer(int t)
    {
        if (t == 2 || t == 3)
            return true;
        if (t % 2 == 0 || t % 3 == 0)
            return false;
        for (int i = 3; i < sqrt(t) + 1; i += 2)
        {
            if (t % i == 0)
                return false;
        }
        return true;
    }
    int countPrimes(int n)
    {
        if (n == 1)
            return 0;
        if (n == 2)
            return 0;
        if (n == 3)
            return 1;
        int c = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrimer(i))
                c++;
        }
        return c;
    }
};
///别人的解法！！！
// int countPrimes(int n)
// {
//     if (n <= 2)
//         return 0;
//     vector<bool> passed(n, false);
//     int sum = 1;
//     int upper = sqrt(n);
//     for (int i = 3; i < n; i += 2)
//     {
//         if (!passed[i])
//         {
//             sum++;
//             //avoid overflow
//             if (i > upper)
//                 continue;
//             for (int j = i * i; j < n; j += i)
//             {
//                 passed[j] = true;
//             }
//         }
//     }
//     return sum;
// }