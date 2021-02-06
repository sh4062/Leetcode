class Solution {
public:
    string ss;
    
    bool isAdditiveNumber(string num) {
        ss = num;
        vector<long double> v;
        return backtrace(num,v);
    }
    bool backtrace(string num,vector<long double>&v){
        if(v.size()>=3&&v[v.size()-2]+v[v.size()-3]!=v[v.size()-1]){
            return false;
        }
        if(num.size()==0&&v.size()>=3)return true;
        for(int i = 0;i<num.size();i++){
            string cur = num.substr(0,i+1);
            if(cur[0]=='0' && cur.size()!=1) continue;
            v.push_back(stold(cur));
            if(backtrace(num.substr(i+1),v))return true;
            v.pop_back();
        }
        return false;

    }
};
