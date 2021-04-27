class Solution {
public:
    // struct cmp{
    // bool operator()(pair<int,int>a,pair<int,int>b){
    //     return abs(a.first-a.second)-abs(b.first-b.second)>0;
    // }
    // };
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        // priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>q;
        // for(int i =0;i<nums.size();i++){
        //     for(int j = i+1;j<nums.size();j++){
                
        //         q.push({nums[i],nums[j]});
        //     }
            
        // }
        // while(k>1){q.pop();k--;}
        // //cout<<q.top().first<<" "<<q.top().second<<endl;
       
        // return abs(q.top().first-q.top().second);
        int l =0,r = nums.back()-nums[0],n=nums.size();
        while(l<r){
            int mid = l+(r-l)/2;
            int count = 0;
            int start = 0;
            for(int i = 0;i<n;i++){
                while(nums[i]-nums[start]>mid)
                start++;
                count+=i-start;
            }
            

            if(count<k )l=mid+1;
            else r=mid;

        }
        return  l;

    }
};
