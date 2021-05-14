class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        string res;
        for(auto i:dictionary){
            int l = 0;
            int flag = 0;
            for(int j=0;j<s.size();j++){
                if(s[j]==i[l])l++;
            } 
            if(l==i.size()) flag=1;
            if(flag){
                if(res.size()<i.size()){
                    res=i;
                }else if(res.size()==i.size()){
                    if(res>i){
                        res=i;
                    }

                }
            }   
        }
        return res;

    }
};
