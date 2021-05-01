class Solution {
public:
   
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ress;
        unordered_set<string> S;  // to search in wordlist in O(1) time.
        for(string &tmp : wordList) 
            S.insert(tmp);
        
        vector<vector<string>> ans;
        if(S.find(endWord) == S.end())
            return ress;   // if endWord doesn't exist in wordList at all, then no need of further process.
        int res = 0;
        queue<vector<string>>q;
        q.push({beginWord});
        int len = 0;
        while(!q.empty()){
            int s = q.size();
            //cout<<s<<endl;
            for(int i = 0;i<q.size();i++){    
                auto tmp = q.front();
                q.pop();
                if(tmp.back() == endWord) {
                    //cout<<"?"<<endl;
                    if(len == 0 or len == tmp.size()) {   // if shortest list of string is found or another list of string with length equals to shortest list of string is found
                        len = tmp.size();
                        ress.push_back(tmp);
                        continue;
                    } else // if current list of string has size more than 'len,' then we will not get any shortest list; just return from here
                        return ress;
                }
                S.erase(tmp.back());
                for(auto b:wordList){
                    int mismatch = 0;
                    for(int i = 0;i<b.size();i++){
                        if(b[i]!=tmp.back()[i])mismatch++;
                        if(mismatch>1)break;
                    }
                    if(mismatch==1){
                        if(S.find(b)!=S.end()){
                            tmp.emplace_back(b);
                            q.push(tmp);
                            S.insert(b); 
                            tmp.pop_back();
                        }

                    }
                }

            }
            //paths_index++;
        }
        //cout<<cnt<<endl;
        return ress;

    }
};
