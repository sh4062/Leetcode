class Solution {
public:
    int adj(string s) {
        if(s.size()==0) return -1;
        int i = 0; 
        for(;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                return i;
            }
        }
        return -1;
    }
    string removeDuplicates(string S) {
        int a = adj(S);
        if(a==-1)return S;
        else{
            S.erase(S.begin()+a,S.begin()+a+2);
                return removeDuplicates(S);
        }
        
    }
};