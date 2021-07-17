class Solution {
public:
    int maximumSwap(int num) {
        if(num<10)return num;
        string s = to_string(num);
        string tmp(s);
        sort(tmp.begin(),tmp.end(),[](char a,char b){return a>b;});
        int p1 = -1;
        for(int i = 0;i<s.size();i++){
            if(tmp[i]!=s[i]){
                p1 = i;
                break;
            }
        }
        if(p1==-1)return num;
        for(int i = s.size()-1;i>=p1+1;i--){
            if(s[i]==tmp[p1]){
                swap(s[i],s[p1]);
                break;
            }
        }
        return stoi(s);

    }
};
