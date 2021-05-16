class Solution {
public:
    string reverseStr(string s, int k) {
        int index = 0;
        while(index+k<=s.size()){
            reverse(s.begin()+index,s.begin()+index+k);
            index+=2*k;
        }
        
        if(index<s.size()&&k>(s.size()-index)){
            reverse(s.begin()+index,s.end());
        }
        return s;

    }
};
