class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int res=0;
        int N=hand.size();
        
        if(N%W!=0)return false;
        if(W==1)return true;
        sort(hand.begin(),hand.end());
        int w=N/W;
        vector<int>vv(W,0);
        unordered_map<int,int>u;
        for(int i = 0;i<N;i++){
             if(u.find(i)!=u.end()){
               continue;
               
             }
            u[i]++;
            int s=i;
            int c= 0;
            for(int k = 0;k<W-1;k++){
                int index=upper_bound( hand.begin(),hand.end(),hand[s])-hand.begin();
                if(index==N)break;
                while(u.find(index)!=u.end())index++;
                if(hand[index]-hand[s]==1){
                u[index]++;
                 c++;
                    }else{
                    return false;
                }
                 s=index;
            }
            if(c==W-1){
                res++;
            }else{
                return false;
            }
         }
        
        if(res==w&&u.size()==N)return true;
        else return false;
    }
};
