class Solution {
private:
    vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    set<string> s;
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if(words.size() == 0 ){
            return 0;
        }
        if(words.size() == 1 ){
            return 1;
        }
        string tmp("");
        for (auto i : words){
            for (auto j : i){
                //cout<<(int(j)-97)<<endl;
               //cout<<code[(int(j)-97)]<<endl;
               tmp = tmp.append(code[(int(j)-97)]);
               //cout<<tmp;
            
            
            }
            s.insert(tmp);
            tmp.clear();
        }
        //s.insert()
        return s.size();
    }
};