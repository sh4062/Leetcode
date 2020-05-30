class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        string p = "Push";
        string pp = "Pop";
        int d = 0;
        int nn = 0;
        for (int i = 1;i<=n;i++){
            if(nn>=target.size())break;
            if(target[nn]-i==0){
                res.push_back(p);
                nn++;
            }else{
                    res.push_back(p);
                    res.push_back(pp);
                }
            }
           
        
        return res;
        
    }
};