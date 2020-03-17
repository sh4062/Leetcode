class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<int> a;
        int c = 0;
        vector<int> pos;
        pos.push_back(0);
        for(int i = 0;i<S.size();i++){
            if(S[i]=='('){
                a.push(0);
            }
            else{
                a.pop();
            }
            if(a.size()==0){
                c++;
                pos.push_back(i);
            }
        }
        //cout<<c;
        //cout<<pos[2];
        string res;  
        for(int i = 0;i<c;i++){
            //cout<<S.substr(pos[i]+1,pos[i+1]-1)<<endl<<pos[i]+1<<endl;
            res+=S.substr(pos[i]+1,pos[i+1]-pos[i]-1);
            pos[i+1]++;
        }
        return res;
    }
};