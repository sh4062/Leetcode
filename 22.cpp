// class Solution {
// public:
//     vector<string> ans;
//     int num;
//     void brackets(string res, int left, int right, int sum)
//     {
//         if(sum == 2 * num) {
//             ans.push_back(res);
//         }
//         else{
//             if(left < right || left < num)brackets(res + '(', left + 1, right, sum + 1);
//             if(left > right)brackets(res + ')', left, right + 1, sum + 1);
//         }
//     }
    
//     vector<string> generateParenthesis(int n) {
//         if(n == 0) return ans;
//         num = n;
//         brackets("", 0, 0, 0);
//         return ans;
//     }
// };


class Solution {
public:
    vector<string> res;
    void dfs(string a,int l,int r){
        if(l==0&&r==0)res.push_back(a);
        if(l>r)return;
        if(l>0){
            
            dfs(a+'(',l-1,r);
        }
        if(r>0){
            
            dfs(a+')',l,r-1);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string a = "";
        dfs(a,n,n);

        return res;
    }
};