class Solution {
public:
    bool isvalid(string S){
        stack<char>st;
        for(int i = 0;i<S.size();i++){
            if(S[i]=='('){
                st.push(S[i]);

            }
            if(S[i]==')'){
                if(st.empty()){
                    return false;
                }
                st.pop();

        }}
        return st.size()==0;
        
    }
    
    vector<string> removeInvalidParentheses(string s) {
        queue<string>q;
        q.push(s);
        set<string>res;
        vector<string>ret;
        int flag = 1;
        int sz = -1;
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
           
            if(isvalid(tmp)){
                ret.push_back(tmp);
                flag = 0;
            }
            
            if(flag)
            for(int i = 0;i<tmp.size();i++){
                if(tmp[i]=='('||tmp[i]==')'){
                string ss = tmp.substr(0,i)+tmp.substr(i+1);
                //cout<<ss<<endl;
                if(!res.count(ss)){
                     res.insert(ss);
                     q.push(ss);
                }
                }

            }


        }
         return ret;
        }

       

    
};
