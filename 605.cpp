class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)return true;
        vector<int>idx;
        for(int i =0;i<flowerbed.size();i++){
           if(flowerbed[i]==1){
               idx.push_back(i);
           }
        }
        for(auto i:idx){
            if(i-1>=0)flowerbed[i-1]=1;
             if(i+1<=flowerbed.size()-1)flowerbed[i+1]=1;
        }
        //for(int i =0;i<flowerbed.size();i++)cout<<flowerbed[i]<<endl;
        int flag = 0;
        for(int i= 0;i<n;i++){
            flag = 0;
            for(int j = 0;j<flowerbed.size();j++){
                
                if(flag==1) continue;
                if(flowerbed[j]==0){
                   
                    flowerbed[j]=1;
                    if(j-1>=0){
                     flowerbed[j-1]=1;
                    }
                        if(j+1<=flowerbed.size()-1){
                         flowerbed[j+1]=1;
                            j+=2;
                       }
                    flag = 1;
                }
                 //cout<<j<<endl;
                
            }
        }
        return flag;
    }
};
