class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        vector<char>st;
        vector<int> hash(26,0);
        int resl=0;
        for(auto i:s){
            hash[i-'a']++;
            if(hash[i-'a']==1)
            resl++;
        }
        //
        for(int i = 0;i<s.size();i++){
            while(st.size()>0&&s[i]<st[st.size()-1]&&hash[st[st.size()-1]-'a'] >1&&find(st.begin(),st.end(),s[i])==st.end()){
                hash[st[st.size()-1]-'a']--;
                cout<<st[st.size()-1]<<endl;
                st.pop_back();
            }
            if(find(st.begin(),st.end(),s[i])==st.end()){

            // hash[s[i]-'a']--;
            st.push_back(s[i]);
            }else{
                hash[s[i]-'a']--;
            }
        }
        //cout<<resl;
        res=string(st.begin(),st.end());
        


        return res.substr(0,resl);

    }
};
