class Solution {
public:
    vector<string> helper(string s){
        vector<string>res;
        if((s.size() > 1 && s[0]!='0') || s.size() == 1) res.push_back(s); //不分隔成小数
         for(int i=1;i<s.size();i++){
            string l = s.substr(0,i);
            string r = s.substr(i);
            
            if(s[0] == '0') return {l + '.' + r}; //小数点前以0开头只有一种符合
            if(r.back() == '0') continue;  //小数点后以0结尾不符合
            res.push_back(l + '.' + r);
        }
        return res;

    }
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        s=s.substr(1,s.size()-2);
        for(int i = 1;i<s.size();i++){
            string l = s.substr(0,i);
            string r = s.substr(i);
            if(l.size() > 1 && l[0]=='0' &&l.back()=='0')continue;
            if(r.size() > 1 && r[0]=='0' &&r.back()=='0')continue;
            auto ll=helper(l);
            auto rr=helper(r);
            for(auto l1:ll){
                for(auto r1:rr){
                    res.push_back("("+l1+", "+r1+")");
                }
            }

        }
        return res;

    }
};
