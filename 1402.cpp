class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int res = 0;
        sort(satisfaction.begin(),satisfaction.end());
        int index0=-1;
        for(int i = 0;i<satisfaction.size();i++){
            if(satisfaction[i]>=0){
                index0 = i;
                break;
            }
        }
        if(index0==-1){
            return 0;
        }
        int s=index0;
        if(index0!=0)
        s = index0-1;
        for(s;s>=0;s--){
            int t = 1;
            int sum = 0;
            for(int i = s;i<satisfaction.size();i++){
                sum+=satisfaction[i]*t;
                t++;
            }
            res = max(res,sum);
        }
        return res;
        
    }
};
