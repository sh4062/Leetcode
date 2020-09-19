class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        string res;
        string tt="";
        string tn="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=']')
                st.push(s[i]);
            else{
                char t=st.top();
                while(t!='['){
                    tt=t+tt;
                    st.pop();
                    t=st.top();
                }
                st.pop();
                
                while(st.size()>0&&st.top()>='0'&&st.top()<='9'){
                     tn=st.top()+tn;
                     st.pop();
                }
                if(tn.size()>0){
                    int sss=stoi(tn);
                    for(int k=0;k<sss;k++){
                        // res+=tt;
                        for(auto kk:tt)
                        st.push(kk);
                    }
                }
                //cout<<tn<<endl;
                //cout<<tt<<endl;
                tt.clear();
                tn.clear();
            }
        }
        while(st.size()>0){
                    tt=st.top()+tt;
                    st.pop();
                    //t=st.top();
        }
        res+=tt;
        //cout<<tt<<endl;
        return res;
    }
};
