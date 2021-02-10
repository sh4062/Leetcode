class Solution {
public:
    string solveEquation(string equation) {
        string res;
        int a1=0,a2=0,b1=0,b2=0;
        stack<int>st;
        //st.push_back();
        int i = 0;
        equation='+'+equation;
        int flag=1;
        for(i=0;i<equation.size();i++){
            //cout<<flag<<endl;
            
            if(equation[i]=='='){
                  equation.insert(equation.begin()+i+1,'+');
                  cout<<equation<<endl;
                  if(!st.empty()){
                    int p = 0;
                    while(!st.empty()){
                        b1+=st.top()*pow(10,p)*flag;
                        st.pop();
                        p++;
                    }
                    }

                
                
                break;
            }
            if(isdigit(equation[i])){
                st.push(equation[i]-'0');
            }
            else if(equation[i]=='x'){
                if(!st.empty()){
                    int p = 0;
                    while(!st.empty()){
                        a1+=st.top()*pow(10,p)*flag;
                        st.pop();
                        p++;
                    }

                }else{
                    a1+=flag;

                }

            }else if(equation[i]=='+'||equation[i]=='-'){
                
                
                if(!st.empty()){
                    int p = 0;
                    while(!st.empty()){
                        b1+=st.top()*pow(10,p)*flag;
                        st.pop();
                        p++;
                    }

                }
                if(equation[i]=='-')flag=-1;
                else flag = 1;

            }

        }
        cout<<a1<<" "<<b1<<endl;
        flag=1;
        for(i;i<equation.size();i++){
             
             if(isdigit(equation[i])){
                st.push(equation[i]-'0');
            }
            else if(equation[i]=='x'){
                if(!st.empty()){
                    int p = 0;
                    while(!st.empty()){
                        a2+=st.top()*pow(10,p)*flag;
                        st.pop();
                        p++;
                    }

                }else{
                    a2+=flag;

                }

            }else if(equation[i]=='+'||equation[i]=='-'){
      
                if(!st.empty()){
                    int p = 0;
                    while(!st.empty()){
                        b2+=st.top()*pow(10,p)*flag;
                        st.pop();
                        p++;
                    }

                }
                if(equation[i]=='-')flag=-1;
                else flag = 1;


            }
            
        }
         if(!st.empty()){
                    int p = 0;
                    while(!st.empty()){
                        b2+=st.top()*pow(10,p)*flag;
                        st.pop();
                        p++;
                    }
                    }
        cout<<a2<<" "<<b2<<endl;
        if(b1-b2==0&&a1-a2==0) return string{"Infinite solutions"};
        if(b1-b2!=0&&a1-a2==0) return string{"No solution"};
        if(b1-b2==0&&a1-a2!=0) return string{"x=0"};
        return "x="+to_string(-(b1-b2)/(a1-a2));

    }
};
