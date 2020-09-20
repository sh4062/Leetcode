// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l = 1;
        long r = n;
        int mid = 0;
        while(l!=r){
            mid=(l+r)/2;
            //cout<<mid;
            if(isBadVersion(mid)&&!isBadVersion(mid-1)){
                //cout<<mid;
                return mid;
            }else if(isBadVersion(mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            if(l==r)return l;
        }

         return mid==0?1:mid;
    }
};
