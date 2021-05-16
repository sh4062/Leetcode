class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<int>res;
        vector<unordered_set<string>>v(favoriteCompanies.size());
        for(int i = 0;i<favoriteCompanies.size();i++){
            for(auto j:favoriteCompanies[i]){
                v[i].insert(j);
            }
        }

        for(int i = 0;i<favoriteCompanies.size();i++){
            int flag = 0;
            for(int j = 0;j<favoriteCompanies.size();j++){
                if(i==j||favoriteCompanies[j].size()<favoriteCompanies[i].size())continue;
                int cnt = 0;
                for(auto c:v[i]){
                    if(v[j].count(c)){
                        cnt++;
                    }else{
                        break;
                    }
                }
                if(cnt==v[i].size()){
                    flag=1;
                }
            }
            if(!flag)res.push_back(i);
        }
        return res;

    }
};
