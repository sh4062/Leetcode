class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i]=="-"||tokens[i]=="+"){
                int tmp2=(st.top());
                st.pop();
                int tmp1=(st.top());
                st.pop();
                if(tokens[i]=="-")
                st.push(tmp1-tmp2);
                if(tokens[i]=="+")
                st.push(tmp1+tmp2);

            }
            else if(tokens[i]=="*"||tokens[i]=="/"){
                int tmp2=(st.top());
                st.pop();
                int tmp1=(st.top());
                st.pop();
                if(tokens[i]=="*")
                st.push(tmp1*tmp2);
                if(tokens[i]=="/")
                st.push(tmp1/tmp2);
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();

    }
};
