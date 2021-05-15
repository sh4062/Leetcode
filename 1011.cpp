class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        while(l<r){
            
            int mid = l+(r-l)/2;
            //cout<<mid<<endl;
            int cur = 0;
            int cnt=1;
            for(int i = 0;i<weights.size();i++){
                cur+=weights[i];
                if(cur>mid){ 
                    cnt++;
                    cur=weights[i];
                }
            }
            //cout<<cnt<<endl;
            if(cnt>days){
                l=mid+1;

            }else{
                r=mid;
            }
        }
        return l;

    }
};
