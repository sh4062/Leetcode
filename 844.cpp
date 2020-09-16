class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string a,b;
        int i=0,j=0;
        for(auto i:S){
            if(a.size()>0&&i=='#'){
                a.pop_back();
            }else{
                if(i!='#')
                a.push_back(i);
            }
        }
        for(auto i:T){
            if(b.size()>0&&i=='#'){
                b.pop_back();
            }else{
                if(i!='#')
                b.push_back(i);
            }
        }
        //cout<<a<<endl;
        //cout<<b<<endl;
        return a.compare(b)==0?true:false;
    }
};
