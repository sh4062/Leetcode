class Solution {
public:
    vector<string> ans; 
    vector<string> letterCasePermutation(string S) {
        dfs(S, 0);
        return ans;
    }
    void dfs(string& S, int index){
        if(index == S.size()){
            ans.push_back(S);
            return;
        }
        //未修改当前字符(字母或者数字)的一条分支
        dfs(S, index+1);
        //修改当前字母的的另一条分支
        if(isalpha(S[index])){
            S[index] = S[index] ^ 32;
            dfs(S, index+1);
        }
    }

};
