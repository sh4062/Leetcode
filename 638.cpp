class Solution {
public:

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
                int k = 0;
        for (int i = 0; i < special.size(); ++i) {
            int s = 0;
            bool match = true;
            for (int j = 0; j < price.size(); ++j) {
                s += price[j] * special[i][j];
                if (special[i][j] > needs[j]) {
                    match = false;
                    break;
                }
            }
            if (match && special[i].back() < s) {
                special[k++] = special[i];
            }
        }
        if (k < special.size()) {
            special.erase(special.begin() + k, special.end());
        }
        // 回溯
        int res = INT_MAX;
        backtrace(price, special, needs, 0, res);
        return res;


    }
    bool valid(const vector<int>& special,const vector<int>& needs){
        for(int i = 0;i<special.size()-1;i++){
            if(special[i]>needs[i]){
                return false;
            }
        }
        return true;
    }
    void backtrace(const vector<int>& price,const vector<vector<int>>& special,vector<int>& needs,int cur,int &res){
        
        if(cur>res){
            return;
        }
        int s = accumulate(needs.begin(),needs.end(),0);
        if(s==0){
            res =min(res,cur);
            return;
        }
        for(int i = 0;i<special.size();i++){
            if(valid(special[i],needs)){
                for(int j = 0;j<needs.size();j++){
                    needs[j]-=special[i][j];
                }
                backtrace(price,special,needs,cur+special[i].back(),res);
                for(int j = 0;j<needs.size();j++){
                    needs[j]+=special[i][j];
                }

            }
        }
        for(int i = 0;i<needs.size();i++){
            if(needs[i]!=0){
                cur+=needs[i]*price[i];
                
            }
        }
        //cout<<cur<<endl;
        res =min(res,cur);


    }
};
