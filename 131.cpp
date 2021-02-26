class Solution {
public:
    vector<vector<string>> res;
    vector<string>cur;
    vector<vector<string>> partition(string s) {
        backtrace(s,0,s.size()-1);
        return res;
    }
    bool is_p(string s){
        //cout<<s<<endl;
        for(int i = 0;i<s.size()/2;i++){
            
            if(s[i]!=s[s.size()-1-i])
            return false;
        }
        
        return true;
    }
    void backtrace(string s,int l,int r){
        if(l>r){
            
            res.push_back(cur);
            return;
        }

        for(int i = 1;i<=r-l+1;i++){
            if(is_p(s.substr(l,i)))
            {
                cur.push_back(s.substr(l,i));
                backtrace(s,l+i,r);
                cur.pop_back();
            }

            
        }
    }
};
