class Solution {
public:
    bool checkValidString(string s) {
        stack<int>st1;
        stack<int>st2;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                st1.push(i);
            }else if(s[i]=='*'){
                st2.push(i);
            }else{
                if(st1.empty()&&st2.empty())return false;
                if(st1.size()>0){
                    st1.pop();
                    continue;
                }else{
                    st2.pop();
                    continue;
                }
            }
        }
        while(!st1.empty()){
            auto tmp = st1.top();
            st1.pop();
            if(st2.empty()){
                return false;
            }
            auto tmp2 = st2.top();
            st2.pop();
            if(tmp2>tmp){
                continue;
            }
            else{
                return false;
            }
        }
        return true;

    }
};
