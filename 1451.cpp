class Solution 
{
public:
    string arrangeWords(string text) 
    {
        //// 变成小写字母
        text[0] = tolower(text[0]);
        //// 以空格切分
        vector<string> text_vec;
        stringstream ss(text);
        string word;
        while (ss >> word)
            text_vec.push_back(word);
        //// 按照单词长度排序----必须是稳定排序
        stable_sort(text_vec.begin(), text_vec.end(), [&](const string &a, const string &b)
        {
            return a.size() < b.size();
        });
        //// 重组，回收
        string res;
        for (string word: text_vec)
        {
            res += word;
            res += ' ';
        }
        res.pop_back();
        res[0] = toupper(res[0]);

        return res;
    }
};
