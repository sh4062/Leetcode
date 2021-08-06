class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int res = 0;
        for(auto i:s){
            if(i=='(')
            st.push(i);
            else{
                if(st.size()>0){
                    st.pop();
                }
                else res++;
            }

        }
        while(!st.empty()){
            res++;
            st.pop();
        }
        return res;

    }
};
