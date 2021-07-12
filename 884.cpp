class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>a,b;
        stringstream ss1(s1);
        stringstream ss2(s2);
        string tmp;
        while(ss1>>tmp){
            a[tmp]++;
        }
        while(ss2>>tmp){
            b[tmp]++;
        }
        vector<string> res;
        for(auto i:a){
            if(i.second==1){
                if(b.find(i.first)==b.end()){
                    res.push_back(i.first);
                }
            }
        }
for(auto i:b){
            if(i.second==1){
                if(a.find(i.first)==a.end()){
                    res.push_back(i.first);
                }
            }
        }
        return res;

    }
};
