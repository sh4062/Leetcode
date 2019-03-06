class Solution {
public:
    //Manacher Alg
string s_new[2002];
int p[2002];
    int Init(string &s)
{
    int len = s.size();
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;

    for (int i = 0; i < len; i++)
    {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }

    s_new[j] = '\0';  // 别忘了哦
    
    return j;  // 返回 s_new 的长度
}
    string longestPalindrome(string s) {
        int len = Init(s);
        int max_len = -1,start=0;
        int id;
        int mx = 0;
        for (int i = 1; i < len; i++)
    {
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i);  // 需 mx 和 2*id-i 的含义
        else
            p[i] = 1;

        while (s_new[i - p[i]] == s_new[i + p[i]])  // 不需边界判断，因为左有'$',右有'\0'
            p[i]++;

        // 我们每走一步 i，都要和 mx 比较，我们希望 mx 尽可能的远，这样才能更有机会执行 if (i < mx)这句代码，从而提高效率
        if (mx < i + p[i])
        {
            id = i;
            mx = i + p[i];
        }
        if(max_len<p[i] - 1){
        
        max_len =  p[i] - 1;
            start = (i-(max_len+1))/2;
       // cout<<i<<start<<max_len;
        }
    }

    return s.substr(start,max_len);
    }
};
