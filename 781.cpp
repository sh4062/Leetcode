class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.size()==0)return 0;
        int res=0;
        map<int,int>mp;
        for(int i =0;i<answers.size();i++){
            mp[answers[i]]++;

        }
        for(auto i:mp){
            if(i.first!=0&&i.second>i.first+1){
            res+=i.second/(i.first+1)*(i.first+1);
            if(i.second%(i.first+1)!=0){
                res+=i.first+1;
            }
            }
            else if(i.first!=0)
            res+=i.first+1;
            else res+=i.second;

        }


        return res;

    }
};
