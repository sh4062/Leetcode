class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int sign = 1;
        if(s[0]=='-')sign = -1;
        stack<int>st1;
        int cur = 0;
        for(int i = 0;i<s.size();i++){
            
            if(isdigit(s[i])){
                cur = s[i]-'0';
                while(i+1<s.size()&&isdigit(s[i+1])){
                    cur = cur*10+(s[i+1]-'0');
                    i++;
                }
                cout<<cur<<endl;
                if(sign==1){
                st1.push(cur*sign);

            }else if(sign==-1){
                 st1.push(cur*sign);


            }else if(sign==3){
                int tmp = st1.top() * cur ;
                st1.pop();
                st1.push(tmp);

            }else if(sign==4){
                int tmp = st1.top() /cur ;
                cout<<st1.top()<<" "<<cur<<endl;
                st1.pop();
                st1.push(tmp);

            }
            }
            else{
            
            if(s[i]=='+')
            sign = 1;
            if(s[i]=='-')
            sign = -1;
            if(s[i]=='*')
            sign = 3;
            if(s[i]=='/')
            sign = 4;
            }
            
        }
         while(!st1.empty()){
             
             res+=st1.top();
             st1.pop();
         }
            
        return res;


    }
};
