class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>m;
        m['b']=0;
        m['a']=0;
        m['l']=0;
        m['o']=0;
        m['n']=0;
        for(auto i:text){
            m[i]=m[i]+1;
        }
        
        int c = 0;
        c = min(m['b'],m['a']);
        c = min(c,m['n']);
        c = min(c,m['l']/2);
        c = min(c,m['o']/2);
        return c;
        
    }
};