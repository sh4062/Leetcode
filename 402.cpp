class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        string res;
        int resl=num.size()-k;
        if(resl==0)return "0";
        for(int i =0;i<num.size();i++){
            while(st.size()>0&&num[i]<st.top()&&k){
                st.pop();
                k--;
            }


            st.push(num[i]);
            

        }
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
           
            
        }
        int qd=0;
        for(auto i:res){
            if(i=='0'){
                qd++;
                resl--;
            }
            else break;
        }

        //cout<<res;
        if(qd==res.size())return "0";
        return res.substr(qd,resl);

    }
};
