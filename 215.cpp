class Solution {
public:
    int partition(vector<int>&v,int l, int r){
        int pivot = v[r];
        int i = l-1;
        for(int j = l;j<r;j++){
            if(v[j]<pivot){
            i++;
            swap(v[i],v[j]);
            }
        }
        swap(v[i+1],v[r]);
        return i+1;


    }
    int randSelect(vector<int>&v,int l,int r){
        int i = rand() % (r - l + 1) + l;
        swap(v[i], v[r]);
        return partition(v, l, r);

    }
    int helper(vector<int>&v,int l, int r,int index){
        int res = randSelect(v,l,r);
        //cout<<res<<endl;
        if(res==index){
            return v[res];
        }else if(res>index){
            return helper(v,l,res-1,index);

        }else if(res<index){
             return helper(v,res+1,r,index);

        }
        return 0;
    }
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums,0,nums.size()-1,nums.size()-k);

    }
};
