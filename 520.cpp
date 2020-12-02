class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word[0]<'a'){
            int c = 1;
            int d = 0;
            for(int i = 1;i<word.size();i++){
                if(word[i]<'a'&&d>0){
                    return false;
                }
                else if(word[i]>='a'&&c!=1){
                    return false;
                }else if(word[i]>='a'){
                    d++;
                }else if(word[i]<'a'){
                     c++;
                }
                
            }
        }else{
            for(auto i:word){
                if(i<'a'){
                    return false;
                    
                }
            }
        }return true;
    }
};
