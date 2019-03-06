class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        unordered_map<char,int>mp;
        if(A.size()==0) return res;
        for(auto i :A[0])mp[i]++;
        if(A.size()==1){
            for(auto j:A[0]){
                res.push_back(string(1,j));
            }
            return res;
        }
        for(int i = 1;i<A.size();i++){
            for(auto j:A[0]){
                if(A[i].find(j)==string::npos){
                    mp[j]=0;
                }
                else {
                    int tmp = count(A[i].begin(),A[i].end(),j);
                    mp[j] = min(tmp,mp[j]);
                }
            }
        }
        for(auto i:mp){
            if(i.second>0){
                for(int ii = 0;ii<i.second;ii++)
                res.push_back(string(1,i.first));
            }
        }
        return res;
        
    }
};