class Solution {
public:
    string reverseParentheses(string s) {
        string res;
        stack<char>st;
        for(auto i:s){
            if(i=='('){
                st.push('(');
            }
            else if(i==')'){
                string t;
                auto tmp = st.top();
                if(tmp!='(')
                t+=tmp;
                st.pop();
                while(tmp!='('){
                    tmp = st.top();
                    st.pop();
                    if(tmp!='(')
                    t+=tmp;
                }

                for(auto j:t){
                    st.push(j);
                }


            }else{
                st.push(i);
            }

        }
        auto tmp = st.top();
        res+=tmp;
        st.pop();
        while(tmp!='('&&!st.empty()){
            tmp = st.top();
            st.pop();
            if(tmp!='(')
            res+=tmp;
        }
        reverse(res.begin(),res.end());
        return res;

    }
};
