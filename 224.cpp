class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int sign = 1;
        int res = 0;
        int len = s.length();
        for(int i = 0;i<len;i++){
            if(isdigit(s[i])){
                int start = s[i]-'0';
                while(i+1<len&&isdigit(s[i+1])){
                    start = start*10+int(s[i+1]-'0');
                    i+=1;
                }
                
                res = res+sign*start;
                //cout<<res<<endl;
                //
            }else if(s[i]=='+'){
                sign = 1;

            }
            else if(s[i]=='-'){
                 sign = -1;
            }
            else if(s[i]=='('){
                st.push(res);
                res = 0;
                st.push(sign);
                sign = 1;
                
            }
            else if(s[i]==')'){
                res = st.top()*res;
                st.pop();
                res +=+st.top();
                st.pop();
                //
                
                
            }
        }
        return res;

    }
};
