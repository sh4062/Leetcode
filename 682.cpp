class Solution {
public:
    string itos(int i)
{
    stringstream s;
    s<<i;
    return s.str();
}
    int calPoints(vector<string>& ops) {
        int res = 0;
        int c1 = 0,  c2 = 0,c3 = 0; 
        stack<int> o;
        for(int i = 0;i<ops.size();i++){
             if(ops[i]=="+"){
                int c = o.top();
                o.pop();
                int d = o.top();
                o.push(c);
                o.push(d+c);
                
                //ops[i] = itos(stoi(ops[i-1])+stoi(ops[i-2]));
                 
            }else if(ops[i]=="D"){
                o.push(2*o.top());
                //ops[i] = itos(2*stoi(ops[i-1]));
            }else if(ops[i]=="C"){
                 o.pop();
                 
            }else {
                o.push(stoi(ops[i]));
            }
            
        }
        while(!o.empty()){
            res+=o.top();
            o.pop();
        }
        return res;
    }
};