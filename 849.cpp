class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
     int len=seats.size();
     int res=0;
     for(int i =0;i<len;i++){
         if(seats[i]==1)continue;
         else{
             
             int d1 =1;
              int d2=1;
              if(i>0){
             for(int j = i-1;j>0;j--){
                 if(seats[j]==1)break;
                 else{
                     d1++;
                     //cout<<d1;
                 }
             }}else{
                  d1=INT_MAX;}
             
             if(i<len-1){
            
             for(int j = i+1;j<len;j++){
                  if(seats[j]==1)break;
                 else{
                     d2++;
                 }
             }
                 }else{d2=INT_MAX;}
             res=max(res,min(d1,d2));
         }
     }
        return res;
    }
};
