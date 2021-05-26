class Solution {
public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string s;
        string res;
        int cnt =1;
        while(ss>>s){
            //cout<<s<<endl;
            if(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='u'||s[0]=='o'||s[0]=='A'||s[0]=='O'||s[0]=='I'||s[0]=='E'||s[0]=='U'){
                res+=s;
                res+="ma";
            }else{
                res+=s.substr(1);
                res+=s[0];
                res+="ma";
            }
            for(int i = 0;i<cnt;i++){
                res+="a";
            }
            res+=" ";
            cnt++;
        }
        
        return res.substr(0,res.size()-1);

    }
};
