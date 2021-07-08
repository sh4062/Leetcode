class Solution {
public:
    vector<string>res;
    unordered_map<int,string>mp;
        
    void dfs(int index,int l,const string& digits,string &tmp){
        if(index==l)res.push_back(tmp);
            for(auto j:mp[digits[index]-'0']){
                tmp.push_back(j);
                dfs(index+1,l,digits,tmp);
                tmp.pop_back();
            }
          
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.size()==0)return res;
        int n = digits.size();
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";mp[5]="jkl";mp[6]="mno";mp[7]="pqrs";mp[8]="tuv";mp[9]="wxyz";
        string tmp;
        dfs(0,n,digits,tmp);
        return res;

    }
};
