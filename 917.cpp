class Solution {
public:
    string reverseOnlyLetters(string S) {
        string res;string tmp;
        for(auto i:S){
            if(isalpha(i)){
                res.push_back('~');
                tmp.push_back(i);
            }
            else{
                res.push_back(i);
            }
        }
        
        int index = tmp.size()-1;
        for(int i = 0;i<S.size();i++){
            if(res[i]=='~'){
                res[i]=tmp[index];
                index--;

            }
        }
        return res;

    }
};
