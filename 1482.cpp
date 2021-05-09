class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<m*k)return -1;
        int maxn = *max_element(bloomDay.begin(),bloomDay.end());
        int minn = *min_element(bloomDay.begin(),bloomDay.end());
        int l = minn;
        int r = maxn;
        while(l<r){
            int mid = l+(r-l)/2;
            int cnt1 = 0;
            int cnt2 = 0;
            for(auto i:bloomDay){
                if(mid>=i){
                    cnt1++;
                    if(cnt1==k){
                        cnt1=0;
                        cnt2++;

                    }

                }else{
                    cnt1=0;
                }
            }
            //cout<<cnt2<<endl;
            if(cnt2<m){
                l=mid+1;

            }else{
                r=mid;

            }

        }
        return l;

    }
};
