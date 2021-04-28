class Solution {
public:
    bool checkIfPangram(string sentence) {
        int cnt = 0;
        set<int>s;
        for(auto i:sentence){
            s.insert(i-'a');

        }
        return s.size()==26;


    }
};
