class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int cnt = 0;  
        int max_in = 0;  
        vector<int>presum(n+1,0);
        for(int i = 1;i<=n;i++){
            if(grumpy[i-1]==1)
            presum[i]=presum[i-1]+customers[i-1];
            else presum[i]=presum[i-1];
        }        
        for(int i = 0;i<n;i++){
            if(grumpy[i]==0){
                cnt+=customers[i];
            }
            int tmp=presum[min(i+minutes,n)]-presum[i];
            max_in=max(max_in,tmp);

        }
        //cout<<max_in;
        return cnt+max_in;

    }
};
