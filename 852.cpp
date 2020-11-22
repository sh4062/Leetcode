class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0,r=arr.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            //cout<<(mid);
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){//mid>0&&mid<arr.size()&&
                return mid;
            }else if(arr[mid]<arr[mid-1]&&arr[mid]>arr[mid+1]){
                r=mid;
            }else{
                l=mid;
            }
        }
        return l;
    }
};
