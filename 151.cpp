class Solution {
public:
    void split(string &s, vector<string> &list1)
{
	istringstream tmp_string(s);
	string ss;
	int i = 0;
    while(s[i]==' ')i++;
    while(i<s.size()){
        if(s[i]==' '){
            if(ss.compare("")!=0)
            list1.push_back(ss);
            
            ss="";
            i++;
            continue;
        }
        if(i==s.size()-1&&s[i]!=' '){
           // cout<<ss<<endl;
             ss+=s[i];
            list1.push_back(ss);
        }
        ss+=s[i];
        i++;
        
    }
    
    
	

}
    string reverseWords(string s) {
        if(s.size()<1)return s;
        
        vector<string>v;
        string res;
        split(s,v);
        for(int i = v.size()-1;i>=1;i--){
           // cout<<v[i]<<endl;
            res+=v[i];
            res+=" ";
        }
        if(v.size()>=1)
        res+=v[0];
        return res;
        
    }
};
